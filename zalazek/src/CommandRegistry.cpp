#include "CommandRegistry.hh"
#include <iostream>
#include <sstream>

using namespace std;

// Wczytanie nowej wtyczki do kolekcji
bool CommandRegistry::RegisterCommand(const string &sLibPath)
{
    shared_ptr<LibInterface> pLibInterface(new LibInterface());

    if (!pLibInterface->LoadLibrary(sLibPath)) // Załadowanie odpowiedniej biblioteki
    {
        cerr << "!!! Błąd: Nie można załadować biblioteki: " << sLibPath << endl;
        return false;
    }
    const char *cmdName = pLibInterface->GetCmdName(); // Pobranie nazwy polecenia
    if (!cmdName)
    {
        cerr << "!!! Błąd: Nie można pobrać nazwy polecenia z: " << sLibPath << endl;
        return false;
    }
    string sCmdName(cmdName); // Rejestracja polecenia w mapie
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

    // W przypadku braku polecenia w kolekcji
    if (it == _commandMap.end())
    {
        cerr << "!!! Błąd: Nieznane polecenie: '" << sCmdName << "'" << endl;
        return nullptr;
    }

    return it->second->CreateCmd();
}

// Przetwarzanie pliku poleceń
bool CommandRegistry::ProcessCommands(istream &rStrm) const
{
    string cmdName;
    bool allSuccess = true;

    while (rStrm >> cmdName)
    {
        map<string, shared_ptr<LibInterface>>::const_iterator pIter = _commandMap.find(cmdName); // Wyszukanie polecenia w kolekcji
        if (pIter == _commandMap.end())
        {
            cerr << "!!! Błąd: Nieznane polecenie '" << cmdName << "'" << endl;
            allSuccess = false;
            rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        AbstractInterp4Command *pCmd = pIter->second->CreateCmd(); // Utworzenie polecenia odpowiadającego nazwie
        if (!pCmd)
        {
            cerr << "!!! Błąd: Nie można utworzyć obiektu polecenia '" << cmdName << "'" << endl;
            allSuccess = false;
            rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        string objName;
        if (cmdName != "Pause") // Przykład dla polecenia "Pause" bez nazwy obiektu
        {
            rStrm >> objName;

            if (rStrm.fail() || objName.empty()) // Sprawdzenie poprawności nazwy obiektu
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
        if (!pCmd->ReadParams(rStrm)) // Wczytanie parametrów polecenia
        {
            cerr << "!!! Błąd: Nie można wczytać parametrów polecenia '" << cmdName << "'" << endl;
            pCmd->PrintSyntax();
            allSuccess = false;
            delete pCmd;
            rStrm.clear();
            rStrm.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        pCmd->PrintCmd(); // Końcowe wyświetlenie polecenia
        delete pCmd;
    }

    return allSuccess;
}