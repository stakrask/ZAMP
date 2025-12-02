#ifndef COMCHANNEL_HH
#define COMCHANNEL_HH

#include "AbstractComChannel.hh"
#include <mutex>
#include <unistd.h>
#include <string>

/*!
 * \file
 * \brief Implementacja kanału komunikacyjnego z serwerem graficznym
 *
 * Klasa implementuje pełną komunikację z serwerem graficznym,
 * łącznie z nawiązywaniem połączenia, wysyłaniem poleceń i zamykaniem.
 */

/*!
 * \brief Pełna implementacja kanału komunikacyjnego z serwerem
 *
 * Klasa zarządza:
 * - Nawiązywaniem połączenia TCP
 * - Wysyłaniem poleceń (thread-safe)
 * - Zamykaniem połączenia
 */
class ComChannel : public AbstractComChannel
{
private:
    int _socket;       ///< Deskryptor gniazda sieciowego
    std::mutex _mutex; ///< Mutex do synchronizacji dostępu

public:
    /*!
     * \brief Konstruktor domyślny
     */
    ComChannel();

    /*!
     * \brief Destruktor - automatycznie zamyka połączenie
     */
    virtual ~ComChannel();

    // Usunięcie konstruktora kopiującego i operatora przypisania
    ComChannel(const ComChannel &) = delete;
    ComChannel &operator=(const ComChannel &) = delete;

    // ===== Implementacja interfejsu AbstractComChannel =====
    
    virtual void Init(int Socket) override;
    virtual int GetSocket() const override;
    virtual void LockAccess() override;
    virtual void UnlockAccess() override;
    virtual std::mutex &UseGuard() override;
    virtual int Send(const char *sMessage) override;
    
    // ===== Wysokopoziomowe API komunikacji =====
    
    /*!
     * \brief Otwiera połączenie z serwerem graficznym
     * 
     * \param[in] sServerAddress - adres IP serwera (domyślnie "127.0.0.1")
     * \param[in] port - port serwera (domyślnie 6217)
     * \return true jeśli połączenie się powiodło
     */
    bool OpenConnection(const char* sServerAddress = "127.0.0.1", int port = 6217);
    
    /*!
     * \brief Zamyka połączenie z serwerem
     * 
     * Wysyła polecenie Close i zamyka gniazdo.
     */
    void CloseConnection();
    
    /*!
     * \brief Sprawdza czy połączenie jest aktywne
     * 
     * \return true jeśli gniazdo jest otwarte
     */
    bool IsConnected() const;
    
    /*!
     * \brief Wysyła polecenie Clear do serwera
     * 
     * \return true jeśli operacja się powiodła
     */
    bool SendClear();
    
    /*!
     * \brief Wysyła polecenie AddObj do serwera
     * 
     * \param[in] sCmd - kompletne polecenie AddObj
     * \return true jeśli operacja się powiodła
     */
    bool SendAddObj(const std::string& sCmd);
    
    /*!
     * \brief Wysyła polecenie UpdateObj do serwera
     * 
     * \param[in] sCmd - kompletne polecenie UpdateObj
     * \return true jeśli operacja się powiodła
     */
    bool SendUpdateObj(const std::string& sCmd);
};

#endif