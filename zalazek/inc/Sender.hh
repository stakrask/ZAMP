#ifndef SENDER_HH
#define SENDER_HH

#include "AbstractComChannel.hh"
#include "AbstractScene.hh"
#include <string>
#include <thread>
#include <atomic>

/*!
 * \file
 * \brief Klasa odpowiedzialna za wysyłanie poleceń do serwera graficznego
 *
 * Sender zarządza połączeniem z serwerem i wysyła polecenia przez ComChannel.
 */

/*!
 * \brief Klasa wysyłająca polecenia do serwera graficznego
 *
 * Odpowiada za:
 * - Nawiązywanie połączenia z serwerem
 * - Wysyłanie poleceń AddObj, UpdateObj, Clear, Close
 * - Monitorowanie zmian na scenie (opcjonalny wątek)
 */
class Sender {
private:
    AbstractComChannel* _pComChannel;  ///< Wskaźnik na kanał komunikacyjny
    AbstractScene* _pScene;            ///< Wskaźnik na scenę (dla wątku)
    std::atomic<bool> _continueLoop;   ///< Flaga kontynuacji wątku
    std::thread _watchThread;          ///< Wątek monitorujący zmiany
    
    /*!
     * \brief Funkcja wątku monitorującego zmiany
     * 
     * Sprawdza okresowo czy scena uległa zmianie i wysyła UpdateObj
     */
    void WatchingLoop();
    
public:
    /*!
     * \brief Konstruktor
     * 
     * \param[in] pComChannel - wskaźnik na kanał komunikacyjny
     * \param[in] pScene - wskaźnik na scenę (opcjonalny, dla wątku)
     */
    Sender(AbstractComChannel* pComChannel, AbstractScene* pScene = nullptr);
    
    /*!
     * \brief Destruktor - zatrzymuje wątek i zamyka połączenie
     */
    ~Sender();
    
    // Usunięcie konstruktora kopiującego i operatora przypisania
    Sender(const Sender&) = delete;
    Sender& operator=(const Sender&) = delete;
    
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
     * \brief Wysyła wiadomość do serwera (thread-safe)
     * 
     * \param[in] sMessage - wiadomość do wysłania (powinna kończyć się '\n')
     * \return 0 w przypadku sukcesu, wartość ujemna w przypadku błędu
     */
    int Send(const char* sMessage);
    
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
    
    /*!
     * \brief Uruchamia wątek monitorujący zmiany na scenie
     * 
     * Wymaga ustawienia wskaźnika na scenę w konstruktorze.
     * Wątek automatycznie wysyła UpdateObj gdy wykryje zmianę.
     * 
     * \return true jeśli wątek został uruchomiony
     */
    bool StartWatchingThread();
    
    /*!
     * \brief Zatrzymuje wątek monitorujący
     * 
     * Metoda blokująca - czeka na zakończenie wątku.
     */
    void StopWatchingThread();
};

#endif