#ifndef COMCHANNEL_HH
#define COMCHANNEL_HH

#include "AbstractComChannel.hh"
#include <mutex>
#include <unistd.h>
#include <cstring>

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
class ComChannel : public AbstractComChannel
{
private:
    int _socket;       ///< Deskryptor gniazda sieciowego
    std::mutex _mutex; ///< Mutex do synchronizacji dostępu

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
    ComChannel(const ComChannel &) = delete;
    ComChannel &operator=(const ComChannel &) = delete;

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
    virtual std::mutex &UseGuard() override;
    /*!
     * \brief Bezpiecznie wysyła wiadomość używając mutexa
     */
    virtual int Send(const char *sMessage) override;
};

#endif