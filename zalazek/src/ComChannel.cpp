#include "ComChannel.hh"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

// Konstruktor
ComChannel::ComChannel() : _socket(-1)
{
}

// Destruktor
ComChannel::~ComChannel()
{
    CloseConnection();
}

// Inicjalizuje deskryptor gniazda
void ComChannel::Init(int Socket)
{
    _socket = Socket;
}

// Udostępnia deskryptor pliku skojarzonego z połączeniem sieciowym z serwerem
int ComChannel::GetSocket() const
{
    return _socket;
}

// Zamyka dostęp do gniazda
void ComChannel::LockAccess()
{
    _mutex.lock();
}

// Otwiera dostęp do gniazda
void ComChannel::UnlockAccess()
{
    _mutex.unlock();
}

// Udostępnia mutex w trybie modyfikacji
std::mutex &ComChannel::UseGuard()
{
    return _mutex;
}

// Wysyła wiadomość do serwera
int ComChannel::Send(const char *sMessage)
{
    if (_socket < 0) {
        cerr << "!!! Błąd: Socket nie jest otwarty." << endl;
        return -1;
    }
    
    // Thread-safe wysyłanie
    lock_guard<mutex> lock(_mutex);
    
    ssize_t totalSent = 0;
    ssize_t toSend = (ssize_t)strlen(sMessage);
    const char *pMessage = sMessage;

    while (toSend > 0)
    {
        ssize_t sent = write(_socket, pMessage, toSend);

        if (sent < 0)
        {
            cerr << "!!! Błąd wysyłania danych." << endl;
            return -1;
        }

        totalSent += sent;
        toSend -= sent;
        pMessage += sent;
    }

    return 0;
}

// Otwiera połączenie z serwerem graficznym
bool ComChannel::OpenConnection(const char* sServerAddress, int port)
{
    struct sockaddr_in serverAddr;
    
    // Wyzerowanie struktury
    bzero((char*)&serverAddr, sizeof(serverAddr));
    
    // Konfiguracja adresu serwera
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(sServerAddress);
    serverAddr.sin_port = htons(port);
    
    // Utworzenie gniazda
    int socket = ::socket(AF_INET, SOCK_STREAM, 0);
    
    if (socket < 0) {
        cerr << "!!! Błąd: Nie można otworzyć gniazda." << endl;
        return false;
    }
    
    // Nawiązanie połączenia
    if (connect(socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "!!! Błąd: Nie można połączyć się z serwerem " 
             << sServerAddress << ":" << port << endl;
        close(socket);
        return false;
    }
    
    // Zapisz deskryptor
    _socket = socket;
    
    cout << "Połączono z serwerem graficznym (" 
         << sServerAddress << ":" << port << ")" << endl;
    
    return true;
}

// Zamyka połączenie z serwerem
void ComChannel::CloseConnection()
{
    if (_socket >= 0) {
        // Wyślij polecenie Close
        const char* closeCmd = "Close\n";
        Send(closeCmd);
        
        // Zamknij gniazdo
        close(_socket);
        _socket = -1;
        
        cout << "Połączenie z serwerem graficznym zamknięte." << endl;
    }
}

// Sprawdza czy połączenie jest aktywne
bool ComChannel::IsConnected() const
{
    return _socket >= 0;
}

// Wysyła polecenie Clear do serwera
bool ComChannel::SendClear()
{
    return Send("Clear\n") == 0;
}

// Wysyła polecenie AddObj do serwera
bool ComChannel::SendAddObj(const std::string& sCmd)
{
    return Send(sCmd.c_str()) == 0;
}

// Wysyła polecenie UpdateObj do serwera
bool ComChannel::SendUpdateObj(const std::string& sCmd)
{
    return Send(sCmd.c_str()) == 0;
}