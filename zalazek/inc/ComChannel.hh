#ifndef COMCHANNEL_HH
#define COMCHANNEL_HH

#include "AbstractComChannel.hh"
#include <mutex>

/*!
 * \file
 * \brief Implementacja kanału komunikacyjnego z serwerem graficznym
 *
 * Klasa implementuje interfejs AbstractComChannel i zapewnia
 * bezpieczną komunikację z serwerem w środowisku wielowątkowym.
 */

/*!
 * \brief Implementacja kanału komunikacyjnego
 *
 * Klasa zarządza połączeniem TCP z serwerem graficznym
 * i zapewnia synchronizację dostępu w środowisku wielowątkowym.
 */
class ComChannel : public AbstractComChannel {
private:
    int _socket;           ///< Deskryptor gniazda sieciowego
    std::mutex _mutex;     ///< Mutex do synchronizacji dostępu
    
public:
    /*!
     * \brief Konstruktor domyślny
     * 
     * Inicjalizuje kanał z nieprawidłowym deskryptorem gniazda.
     */
    ComChannel();
    
    /*!
     * \brief Destruktor
     * 
     * Zamyka połączenie jeśli jest otwarte.
     */
    virtual ~ComChannel();
    
    // Usunięcie konstruktora kopiującego i operatora przypisania
    ComChannel(const ComChannel&) = delete;
    ComChannel& operator=(const ComChannel&) = delete;
    
    /*!
     * \brief Inicjalizuje deskryptor gniazda
     * 
     * \param[in] Socket - poprawny deskryptor gniazda
     */
    virtual void Init(int Socket) override;
    
    /*!
     * \brief Zwraca deskryptor gniazda
     * 
     * \return Deskryptor gniazda lub -1 jeśli nie zainicjalizowane
     */
    virtual int GetSocket() const override;
    
    /*!
     * \brief Blokuje dostęp do gniazda (lock mutex)
     * 
     * Metoda blokuje wątek do momentu uzyskania dostępu.
     */
    virtual void LockAccess() override;
    
    /*!
     * \brief Odblokuje dostęp do gniazda (unlock mutex)
     */
    virtual void UnlockAccess() override;
    
    /*!
     * \brief Zwraca referencję do mutexa
     * 
     * Umożliwia użycie std::lock_guard lub std::unique_lock.
     * \return Referencja do wewnętrznego mutexa
     */
    virtual std::mutex& UseGuard() override;
    
    /*!
     * \brief Wysyła wiadomość do serwera
     * 
     * Metoda automatycznie blokuje dostęp (thread-safe).
     * \param[in] sMessage - wiadomość do wysłania (powinna kończyć się '\n')
     * \return 0 w przypadku sukcesu, wartość ujemna w przypadku błędu
     */
    int Send(const char* sMessage);
    
    /*!
     * \brief Otwiera połączenie z serwerem graficznym
     * 
     * \param[in] sServerAddress - adres IP serwera (domyślnie "127.0.0.1")
     * \param[in] port - port serwera (domyślnie 6217)
     * \return true jeśli połączenie się powiodło
     */
    bool Open(const char* sServerAddress = "127.0.0.1", int port = 6217);
    
    /*!
     * \brief Zamyka połączenie z serwerem
     * 
     * Wysyła polecenie Close i zamyka gniazdo.
     */
    void Close();
    
    /*!
     * \brief Sprawdza czy połączenie jest aktywne
     * 
     * \return true jeśli gniazdo jest otwarte
     */
    bool IsOpen() const;
};

#endif