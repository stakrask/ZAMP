#include "ComChannel.hh"
#include <unistd.h>

// Konstruktor
ComChannel::ComChannel() : _socket(-1)
{
}

// Destruktor
ComChannel::~ComChannel()
{
    if (_socket >= 0) {
        close(_socket);
        _socket = -1;
    }
}

// Inicjalizacja deskryptora gniazda
void ComChannel::Init(int Socket)
{
    _socket = Socket;
}

// Zwraca deskryptor gniazda
int ComChannel::GetSocket() const
{
    return _socket;
}

// Blokuje dostęp do gniazda
void ComChannel::LockAccess()
{
    _mutex.lock();
}

// Odblokowuje dostęp do gniazda
void ComChannel::UnlockAccess()
{
    _mutex.unlock();
}

// Zwraca referencję do mutexa
std::mutex& ComChannel::UseGuard()
{
    return _mutex;
}