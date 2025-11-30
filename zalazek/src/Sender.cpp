#include "Sender.hh"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>

using namespace std;

// Konstruktor
Sender::Sender(AbstractComChannel* pComChannel, AbstractScene* pScene)
    : _pComChannel(pComChannel)
    , _pScene(pScene)
    , _continueLoop(false)
{
}

// Destruktor
Sender::~Sender()
{
    StopWatchingThread();
    CloseConnection();
}

// Otwiera połączenie z serwerem
bool Sender::OpenConnection(const char* sServerAddress, int port)
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
    
    // Przekaż deskryptor do ComChannel
    _pComChannel->Init(socket);
    
    cout << "Połączono z serwerem graficznym (" 
         << sServerAddress << ":" << port << ")" << endl;
    
    return true;
}

// Zamyka połączenie z serwerem
void Sender::CloseConnection()
{
    int socket = _pComChannel->GetSocket();
    
    if (socket >= 0) {
        // Wyślij polecenie Close
        const char* closeCmd = "Close\n";
        Send(closeCmd);
        
        // Zamknij gniazdo
        close(socket);
        _pComChannel->Init(-1);
        
        cout << "Połączenie z serwerem graficznym zamknięte." << endl;
    }
}

// Sprawdza czy połączenie jest aktywne
bool Sender::IsConnected() const
{
    return _pComChannel->GetSocket() >= 0;
}

// Wysyła wiadomość do serwera (thread-safe)
int Sender::Send(const char* sMessage)
{
    int socket = _pComChannel->GetSocket();
    
    if (socket < 0) {
        cerr << "!!! Błąd: Kanał komunikacyjny nie jest otwarty." << endl;
        return -1;
    }
    
    // Automatyczna blokada dostępu
    lock_guard<mutex> lock(_pComChannel->UseGuard());
    
    ssize_t totalSent = 0;
    ssize_t toSend = (ssize_t)strlen(sMessage);
    const char* pMessage = sMessage;
    
    while (toSend > 0) {
        ssize_t sent = write(socket, pMessage, toSend);
        
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

// Wysyła polecenie Clear
bool Sender::SendClear()
{
    return Send("Clear\n") == 0;
}

// Wysyła polecenie AddObj
bool Sender::SendAddObj(const std::string& sCmd)
{
    return Send(sCmd.c_str()) == 0;
}

// Wysyła polecenie UpdateObj
bool Sender::SendUpdateObj(const std::string& sCmd)
{
    return Send(sCmd.c_str()) == 0;
}

// Funkcja wątku monitorującego zmiany
void Sender::WatchingLoop()
{
    if (!_pScene) {
        cerr << "!!! Błąd: Brak sceny do monitorowania." << endl;
        return;
    }
    
    cout << "Wątek monitorujący uruchomiony." << endl;
    
    while (_continueLoop) {
        // TODO: Tu powinna być logika sprawdzania zmian na scenie
        // Np. poprzez AccessControl lub podobny mechanizm
        
        // Na razie po prostu czekamy
        usleep(10000); // 10ms
    }
    
    cout << "Wątek monitorujący zatrzymany." << endl;
}

// Uruchamia wątek monitorujący
bool Sender::StartWatchingThread()
{
    if (!_pScene) {
        cerr << "!!! Błąd: Nie można uruchomić wątku bez sceny." << endl;
        return false;
    }
    
    if (_continueLoop) {
        cerr << "!!! Ostrzeżenie: Wątek już działa." << endl;
        return false;
    }
    
    _continueLoop = true;
    _watchThread = thread(&Sender::WatchingLoop, this);
    
    return true;
}

// Zatrzymuje wątek monitorujący
void Sender::StopWatchingThread()
{
    if (_continueLoop) {
        _continueLoop = false;
        
        if (_watchThread.joinable()) {
            _watchThread.join();
        }
    }
}