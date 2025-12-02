#include "ComChannel.hh"


// Konstruktor
ComChannel::ComChannel() : _socket(-1)
{
}

// Destruktor
ComChannel::~ComChannel()
{
    if (_socket >= 0)
    {
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
std::mutex &ComChannel::UseGuard()
{
    return _mutex;
}
int ComChannel::Send(const char *sMessage)
{
    if (_socket < 0)
    {
        return -1;
    }

    // Automatyczna blokada dostępu
    std::lock_guard<std::mutex> lock(_mutex);

    ssize_t totalSent = 0;
    ssize_t toSend = (ssize_t)strlen(sMessage);
    const char *pMessage = sMessage;

    while (toSend > 0)
    {
        ssize_t sent = write(_socket, pMessage, toSend);

        if (sent < 0)
        {
            return -1;
        }

        totalSent += sent;
        toSend -= sent;
        pMessage += sent;
    }

    return 0;
}