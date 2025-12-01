#ifndef COMMANDREGISTRY_HH
#define COMMANDREGISTRY_HH

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <thread>
#include "LibInterface.hh"
#include "AbstractInterp4Command.hh"
#include "AbstractScene.hh"
#include "AbstractComChannel.hh"

/*!
 * \file
 * \brief Zawiera definicję klasy CommandRegistry
 *
 * Zawiera definicję klasy CommandRegistry, która zarządza
 * rejestrem dostępnych poleceń i ich wtyczek.
 */

/*!
 * \brief Struktura przechowująca informacje o pojedynczym poleceniu do wykonania
 */
struct CommandTask {
    std::string cmdName;        ///< Nazwa polecenia (np. "Move", "Rotate")
    std::string objectName;     ///< Nazwa obiektu (jeśli wymagana)
    std::string paramsLine;     ///< Linia z parametrami polecenia
};

/*!
 * \brief Rejestr poleceń łączący nazwy z wtyczkami
 *
 * Klasa zarządza mapowaniem nazw poleceń na odpowiadające
 * im wtyczki. Umożliwia dynamiczne tworzenie obiektów poleceń
 * na podstawie nazwy oraz wykonywanie poleceń z pliku.
 * Obsługuje również wielowątkowe wykonywanie poleceń.
 */
class CommandRegistry {
private:
    /*!
     * \brief Mapa łącząca nazwy poleceń z interfejsami bibliotek
     */
    std::map<std::string, std::shared_ptr<LibInterface>> _commandMap;

    /*!
     * \brief Funkcja wykonywana przez wątek roboczy
     * 
     * Wykonuje pojedyncze polecenie w osobnym wątku.
     * \param[in] task - zadanie do wykonania (polecenie + parametry)
     * \param[in,out] rScene - scena z obiektami mobilnymi
     * \param[in,out] rComChannel - kanał komunikacyjny z serwerem
     */
    void ExecuteCommandInThread(const CommandTask& task,
                               AbstractScene& rScene,
                               AbstractComChannel& rComChannel) const;

public:
    /*!
     * \brief Konstruktor domyślny
     */
    CommandRegistry() = default;
    
    /*!
     * \brief Destruktor
     */
    ~CommandRegistry() = default;
    
    // Usunięcie konstruktora kopiującego i operatora przypisania
    CommandRegistry(const CommandRegistry&) = delete;
    CommandRegistry& operator=(const CommandRegistry&) = delete;
    
    /*!
     * \brief Rejestruje nową wtyczkę w rejestrze
     *
     * Ładuje bibliotekę z podanej ścieżki i rejestruje ją
     * pod nazwą polecenia, które implementuje.
     * \param[in] sLibPath - ścieżka do pliku biblioteki (.so)
     * \retval true - wtyczka została pomyślnie zarejestrowana
     * \retval false - błąd podczas ładowania lub rejestracji
     */
    bool RegisterCommand(const std::string& sLibPath);
    
    /*!
     * \brief Tworzy obiekt polecenia na podstawie nazwy
     *
     * Wyszukuje wtyczkę odpowiadającą podanej nazwie polecenia
     * i tworzy nową instancję tego polecenia.
     * \param[in] sCmdName - nazwa polecenia
     * \return Wskaźnik do utworzonego obiektu polecenia lub nullptr w przypadku błędu
     */
    AbstractInterp4Command* CreateCommand(const std::string& sCmdName) const;
    
    /*!
     * \brief Przetwarza plik poleceń z wykonaniem
     *
     * Wczytuje i wykonuje polecenia z podanego strumienia.
     * Obsługuje sekcje Begin_Parallel_Actions / End_Parallel_Actions
     * dla wielowątkowego wykonywania poleceń.
     * \param[in] rStrm - strumień zawierający przetworzony plik poleceń
     * \param[in,out] rScene - scena z obiektami mobilnymi
     * \param[in,out] rComChannel - kanał komunikacyjny z serwerem
     * \retval true - wszystkie polecenia zostały przetworzone
     * \retval false - wystąpił błąd podczas przetwarzania
     */
    bool ProcessCommands(std::istream& rStrm,
                        AbstractScene& rScene,
                        AbstractComChannel& rComChannel) const;
};

#endif