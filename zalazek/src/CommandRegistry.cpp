#include "CommandRegistry.hh"
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

// Wczytanie nowej wtyczki do kolekcji
bool CommandRegistry::RegisterCommand(const string &sLibPath)
{
    shared_ptr<LibInterface> pLibInterface(new LibInterface());

    if (!pLibInterface->LoadLibrary(sLibPath))
    {
        cerr << "!!! Błąd: Nie można załadować biblioteki: " << sLibPath << endl;
        return false;
    }
    const char *cmdName = pLibInterface->GetCmdName();
    if (!cmdName)
    {
        cerr << "!!! Błąd: Nie można pobrać nazwy polecenia z: " << sLibPath << endl;
        return false;
    }
    string sCmdName(cmdName);
    if (_commandMap.find(sCmdName) != _commandMap.end())
    {
        cerr << "!!! Ostrzeżenie: Polecenie '" << sCmdName
             << "' jest już zarejestrowane. Zastępuję." << endl;
    }
    _commandMap[sCmdName] = pLibInterface;

    return true;
}

// Utworzenie polecenia na podstawie nazwy
AbstractInterp4Command *CommandRegistry::CreateCommand(const string &sCmdName) const
{
    map<string, shared_ptr<LibInterface>>::const_iterator it = _commandMap.find(sCmdName);

    if (it == _commandMap.end())
    {
        cerr << "!!! Błąd: Nieznane polecenie: '" << sCmdName << "'" << endl;
        return nullptr;
    }

    return it->second->CreateCmd();
}

// Funkcja wykonywana w osobnym wątku
void CommandRegistry::ExecuteCommandInThread(const CommandTask& task,
                                             AbstractScene& rScene,
                                             AbstractComChannel& rComChannel) const
{
    cout << "[Wątek " << this_thread::get_id() << "] Rozpoczynam: " 
         << task.cmdName << " " << task.objectName << endl;

    // Znajdź polecenie w mapie
    auto pIter = _commandMap.find(task.cmdName);
    if (pIter == _commandMap.end()) {
        cerr << "[Wątek " << this_thread::get_id() << "] Błąd: Nieznane polecenie '" 
             << task.cmdName << "'" << endl;
        return;
    }

    // Utwórz instancję polecenia
    AbstractInterp4Command* pCmd = pIter->second->CreateCmd();
    if (!pCmd) {
        cerr << "[Wątek " << this_thread::get_id() << "] Błąd: Nie można utworzyć polecenia." << endl;
        return;
    }

    // Wczytaj parametry z linii
    istringstream paramStream(task.paramsLine);
    if (!pCmd->ReadParams(paramStream)) {
        cerr << "[Wątek " << this_thread::get_id() << "] Błąd: Nie można wczytać parametrów." << endl;
        pCmd->PrintSyntax();
        delete pCmd;
        return;
    }

    // Wyświetl polecenie
    cout << "[Wątek " << this_thread::get_id() << "] ";
    pCmd->PrintCmd();

    // Wykonaj polecenie
    if (!pCmd->ExecCmd(rScene, task.objectName.c_str(), rComChannel)) {
        cerr << "[Wątek " << this_thread::get_id() << "] Błąd wykonania polecenia." << endl;
    }

    delete pCmd;
    
    cout << "[Wątek " << this_thread::get_id() << "] Zakończono: " 
         << task.cmdName << " " << task.objectName << endl;
}

// Przetwarzanie pliku poleceń z wykonywaniem ExecCmd
bool CommandRegistry::ProcessCommands(istream &rStrm,
                                      AbstractScene &rScene,
                                      AbstractComChannel &rComChannel) const
{
    string cmdName;
    bool allSuccess = true;
    bool inParallelSection = false;
    vector<CommandTask> parallelTasks;  // Zadania do wykonania równolegle

    while (rStrm >> cmdName)
    {
        // === Rozpoczęcie sekcji równoległej ===
        if (cmdName == "Begin_Parallel_Actions")
        {
            cout << "\n======================================" << endl;
            cout << "=== BEGIN PARALLEL ACTIONS ===" << endl;
            cout << "======================================" << endl;
            inParallelSection = true;
            parallelTasks.clear();
            continue;
        }

        // === Zakończenie sekcji równoległej ===
        if (cmdName == "End_Parallel_Actions")
        {
            cout << "\n--- Uruchamiam " << parallelTasks.size() << " wątków ---" << endl;
            
            // Utwórz wątki dla wszystkich zebranych zadań
            vector<thread> threads;
            threads.reserve(parallelTasks.size());
            
            for (const auto& task : parallelTasks) {
                threads.emplace_back(
                    &CommandRegistry::ExecuteCommandInThread,
                    this,
                    task,
                    ref(rScene),
                    ref(rComChannel)
                );
            }
            
            // Czekaj na zakończenie wszystkich wątków
            cout << "Oczekiwanie na zakończenie wątków..." << endl;
            for (auto& t : threads) {
                if (t.joinable()) {
                    t.join();
                }
            }
            
            cout << "======================================" << endl;
            cout << "=== END PARALLEL ACTIONS ===" << endl;
            cout << "======================================\n" << endl;
            
            inParallelSection = false;
            parallelTasks.clear();
            continue;
        }

        // === Przygotowanie zadania ===
        CommandTask task;
        task.cmdName = cmdName;

        // Wczytaj nazwę obiektu (jeśli to nie Pause)
        if (cmdName != "Pause") {
            rStrm >> task.objectName;
            
            if (rStrm.fail() || task.objectName.empty()) {
                cerr << "!!! Błąd: Brak nazwy obiektu dla polecenia '" << cmdName << "'" << endl;
                allSuccess = false;
                rStrm.clear();
                rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }

        // Wczytaj resztę linii jako parametry
        getline(rStrm, task.paramsLine);
        
        // Usuń wiodące spacje
        size_t firstNonSpace = task.paramsLine.find_first_not_of(" \t");
        if (firstNonSpace != string::npos) {
            task.paramsLine = task.paramsLine.substr(firstNonSpace);
        }

        // === Tryb równoległy - dodaj do kolejki ===
        if (inParallelSection) {
            cout << "  [Kolejkuję] " << task.cmdName << " " << task.objectName 
                 << " (parametry: " << task.paramsLine << ")" << endl;
            parallelTasks.push_back(task);
            continue;
        }

        // === Tryb sekwencyjny - wykonaj natychmiast ===
        auto pIter = _commandMap.find(cmdName);
        if (pIter == _commandMap.end())
        {
            cerr << "!!! Błąd: Nieznane polecenie '" << cmdName << "'" << endl;
            allSuccess = false;
            continue;
        }

        AbstractInterp4Command *pCmd = pIter->second->CreateCmd();
        if (!pCmd)
        {
            cerr << "!!! Błąd: Nie można utworzyć obiektu polecenia '" << cmdName << "'" << endl;
            allSuccess = false;
            continue;
        }

        istringstream paramStream(task.paramsLine);
        if (!pCmd->ReadParams(paramStream))
        {
            cerr << "!!! Błąd: Nie można wczytać parametrów polecenia '" << cmdName << "'" << endl;
            pCmd->PrintSyntax();
            allSuccess = false;
            delete pCmd;
            continue;
        }

        cout << "\n--- Polecenie: ";
        pCmd->PrintCmd();

        if (!pCmd->ExecCmd(rScene, task.objectName.c_str(), rComChannel))
        {
            cerr << "!!! Błąd: Wykonanie polecenia '" << cmdName << "' nie powiodło się." << endl;
            allSuccess = false;
        }

        delete pCmd;
    }

    // Sprawdź czy nie zapomniano zamknąć sekcji równoległej
    if (inParallelSection) {
        cerr << "!!! Ostrzeżenie: Sekcja Begin_Parallel_Actions nie została zamknięta przez End_Parallel_Actions!" << endl;
        allSuccess = false;
    }

    return allSuccess;
}