#include "CommandRegistry.hh"
#include <iostream>
#include <sstream>

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

// Przetwarzanie pliku poleceń z wykonywaniem ExecCmd
bool CommandRegistry::ProcessCommands(istream &rStrm,
                                      AbstractScene &rScene,
                                      AbstractComChannel &rComChannel) const
{
    string cmdName;
    bool allSuccess = true;

    while (rStrm >> cmdName)
    {
        if (cmdName == "Begin_Parallel_Actions")
        {
            cout << "\n--- Polecenie: Begin_Parallel_Actions (na razie brak wsparcia wielowątkowości)" << endl;
            continue;
        }

        if (cmdName == "End_Parallel_Actions")
        {
            cout << "--- Polecenie: End_Parallel_Actions (na razie brak wsparcia wielowątkowości)" << endl;
            continue;
        }
        // Wyszukanie polecenia w kolekcji
        map<string, shared_ptr<LibInterface>>::const_iterator pIter = _commandMap.find(cmdName);
        if (pIter == _commandMap.end())
        {
            cerr << "!!! Błąd: Nieznane polecenie '" << cmdName << "'" << endl;
            allSuccess = false;
            rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Utworzenie polecenia
        AbstractInterp4Command *pCmd = pIter->second->CreateCmd();
        if (!pCmd)
        {
            cerr << "!!! Błąd: Nie można utworzyć obiektu polecenia '" << cmdName << "'" << endl;
            allSuccess = false;
            rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Wczytaj nazwę obiektu (jeśli nie jest to Pause)
        string objName;
        if (cmdName != "Pause")
        {
            rStrm >> objName;

            if (rStrm.fail() || objName.empty())
            {
                cerr << "!!! Błąd: Brak nazwy obiektu dla polecenia '" << cmdName << "'" << endl;
                pCmd->PrintSyntax();
                allSuccess = false;
                delete pCmd;
                rStrm.clear();
                rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }

        // Wczytanie parametrów polecenia
        if (!pCmd->ReadParams(rStrm))
        {
            cerr << "!!! Błąd: Nie można wczytać parametrów polecenia '" << cmdName << "'" << endl;
            pCmd->PrintSyntax();
            allSuccess = false;
            delete pCmd;
            rStrm.clear();
            rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Wyświetl polecenie
        cout << "\n--- Polecenie: ";
        pCmd->PrintCmd();

        // Wykonaj polecenie
        if (!pCmd->ExecCmd(rScene, objName.c_str(), rComChannel))
        {
            cerr << "!!! Błąd: Wykonanie polecenia '" << cmdName << "' nie powiodło się." << endl;
            allSuccess = false;
        }

        delete pCmd;
    }

    return allSuccess;
}