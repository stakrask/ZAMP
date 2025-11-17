#include "ComChannel.hh"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

ComChannel::ComChannel() : _socket(-1)
{
}

ComChannel::~ComChannel()
{
    if (_socket >= 0) {
        Close();
    }
}

void ComChannel::Init(int Socket)
{
    _socket = Socket;
}

int ComChannel::GetSocket() const
{
    return _socket;
}

void ComChannel::LockAccess()
{
    _mutex.lock();
}

void ComChannel::UnlockAccess()
{
    _mutex.unlock();
}

std::mutex& ComChannel::UseGuard()
{
    return _mutex;
}

bool ComChannel::Open(const char* sServerAddress, int port)
{
    struct sockaddr_in serverAddr;
    
    // Wyzerowanie struktury
    bzero((char*)&serverAddr, sizeof(serverAddr));
    
    // Konfiguracja adresu serwera
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(sServerAddress);
    serverAddr.sin_port = htons(port);
    
    // Utworzenie gniazda
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (_socket < 0) {
        cerr << "!!! Błąd: Nie można otworzyć gniazda." << endl;
        return false;
    }
    
    // Nawiązanie połączenia
    if (connect(_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "!!! Błąd: Nie można połączyć się z serwerem " 
             << sServerAddress << ":" << port << endl;
        close(_socket);
        _socket = -1;
        return false;
    }
    
    cout << "Połączono z serwerem graficznym (" 
         << sServerAddress << ":" << port << ")" << endl;
    
    return true;
}

int ComChannel::Send(const char* sMessage)
{
    if (_socket < 0) {
        cerr << "!!! Błąd: Kanał komunikacyjny nie jest otwarty." << endl;
        return -1;
    }
    
    // Automatyczna blokada dostępu
    lock_guard<mutex> lock(_mutex);
    
    ssize_t totalSent = 0;
    ssize_t toSend = (ssize_t)strlen(sMessage);
    const char* pMessage = sMessage;
    
    while (toSend > 0) {
        ssize_t sent = write(_socket, pMessage, toSend);
        
        if (sent < 0) {
            cerr << "!!! Błąd: Nie udało się wysłać wiadomości." << endl;
            return -1;
        }
        
        totalSent += sent;
        toSend -= sent;
        pMessage += sent;
    }
    
    return 0;
}

void ComChannel::Close()
{
    if (_socket >= 0) {
        // Wyślij polecenie Close do serwera
        const char* closeCmd = "Close\n";
        
        // Nie używaj Send() bo to wywoła lock_guard na już zamkniętym obiekcie
        write(_socket, closeCmd, strlen(closeCmd));
        
        // Zamknij gniazdo
        close(_socket);
        _socket = -1;
        
        cout << "Połączenie z serwerem graficznym zamknięte." << endl;
    }
}

bool ComChannel::IsOpen() const
{
    return _socket >= 0;
}