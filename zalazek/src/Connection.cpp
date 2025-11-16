#include "Connection.hh"
#include <iostream>
#include <cstring>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

// Docelowy numer portu
#define PORT 6217

bool OpenConnection(int& rSocket) {
    struct sockaddr_in DaneAdSerw;
    
    // Wyzerowanie struktury
    bzero((char*)&DaneAdSerw, sizeof(DaneAdSerw));
    
    // Konfiguracja adresu serwera
    DaneAdSerw.sin_family = AF_INET;
    DaneAdSerw.sin_addr.s_addr = inet_addr("127.0.0.1");
    DaneAdSerw.sin_port = htons(PORT);
    
    // Utworzenie gniazda
    rSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (rSocket < 0) {
        cerr << "!!! Błąd: Nie można otworzyć gniazda." << endl;
        return false;
    }
    
    if (connect(rSocket, (struct sockaddr*)&DaneAdSerw, sizeof(DaneAdSerw)) < 0) {
        cerr << "!!! Błąd: Nie można połączyć się z serwerem na porcie " << PORT << endl;
        close(rSocket);
        rSocket = -1;
        return false;
    }
    
    cout << "Połączono z serwerem graficznym." << endl;
    
    return true;
}

int Send(int Socket, const char* sMessage) {
    if (Socket < 0) {
        cerr << "!!! Błąd: Nieprawidłowy deskryptor gniazda." << endl;
        return -1;
    }
    
    ssize_t IlWyslanych;
    ssize_t IlDoWyslania = (ssize_t)strlen(sMessage);
    const char* pMessage = sMessage;
    
    while ((IlWyslanych = write(Socket, pMessage, IlDoWyslania)) > 0) {
        IlDoWyslania -= IlWyslanych;
        pMessage += IlWyslanych;
        
        if (IlDoWyslania <= 0) break;
    }
    
    if (IlWyslanych < 0) {
        cerr << "!!! Błąd: Nie udało się wysłać wiadomości." << endl;
        return -1;
    }
    
    return 0;
}


void CloseConnection(int Socket) {
    if (Socket >= 0) {
        Send(Socket, "Close\n");
        close(Socket);
    }
}