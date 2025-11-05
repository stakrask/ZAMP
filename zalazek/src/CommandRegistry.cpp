#include "CommandRegistry.hh"
#include <iostream>
#include <sstream>

using namespace std;

bool CommandRegistry::RegisterCommand(const string& sLibPath) {
    auto pLibInterface = make_unique<LibInterface>();
    
    if (!pLibInterface->LoadLibrary(sLibPath)) {
        cerr << "!!! Błąd: Nie można załadować biblioteki: " << sLibPath << endl;
        return false;
    }
    
    const char* cmdName = pLibInterface->GetCmdName();
    if (!cmdName) {
        cerr << "!!! Błąd: Nie można pobrać nazwy polecenia z: " << sLibPath << endl;
        return false;
    }
    
    string sCmdName(cmdName);
    
    // Sprawdź czy polecenie już istnieje
    if (_commandMap.find(sCmdName) != _commandMap.end()) {
        cerr << "!!! Ostrzeżenie: Polecenie '" << sCmdName 
             << "' jest już zarejestrowane. Zastępuję." << endl;
    }
    
    _commandMap[sCmdName] = move(pLibInterface);
    cout << "Zarejestrowano polecenie: " << sCmdName << endl;
    
    return true;
}

AbstractInterp4Command* CommandRegistry::CreateCommand(const string& sCmdName) const {
    auto it = _commandMap.find(sCmdName);
    
    if (it == _commandMap.end()) {
        cerr << "!!! Błąd: Nieznane polecenie: '" << sCmdName << "'" << endl;
        return nullptr;
    }
    
    return it->second->CreateCmd();
}

bool CommandRegistry::ProcessCommands(istream& rStrm) const {
    string line;
    int lineNumber = 0;
    bool allSuccess = true;
    
    cout << "\nPrzetwarzanie poleceń" << endl;
    
    while (getline(rStrm, line)) {
        lineNumber++;
        
        // Pomiń puste linie i komentarze
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // Usuń białe znaki z początku
        size_t start = line.find_first_not_of(" \t\r\n");
        if (start == string::npos) {
            continue;
        }
        line = line.substr(start);
        
        // Wyodrębnij nazwę polecenia (pierwsze słowo)
        istringstream lineStream(line);
        string cmdName;
        lineStream >> cmdName;
        
        if (cmdName.empty()) {
            continue;
        }
        
        cout << "\n--- Linia " << lineNumber << " ---" << endl;
        cout << "Polecenie: " << cmdName << endl;
        
        // Utwórz obiekt polecenia
        AbstractInterp4Command* pCmd = CreateCommand(cmdName);
        
        if (!pCmd) {
            cerr << "!!! Błąd w linii " << lineNumber 
                 << ": Nie można utworzyć polecenia '" << cmdName << "'" << endl;
            allSuccess = false;
            continue;
        }
        
        // Wczytaj parametry
        if (!pCmd->ReadParams(lineStream)) {
            cerr << "!!! Błąd w linii " << lineNumber 
                 << ": Nie można wczytać parametrów polecenia '" << cmdName << "'" << endl;
            cout << "Oczekiwana składnia:" << endl;
            pCmd->PrintSyntax();
            allSuccess = false;
            delete pCmd;
            continue;
        }
        
        // Wyświetl wczytane parametry
        cout << "Parametry: ";
        pCmd->PrintParams();
        
        // Wyświetl pełne polecenie
        cout << "Pełna postać: ";
        pCmd->PrintCmd();
        
        delete pCmd;
    }
      
    return allSuccess;
}

void CommandRegistry::PrintAvailableCommands() const {
    cout << "\nDostępne polecenia" << endl;
    
    if (_commandMap.empty()) {
        cout << "Brak zarejestrowanych poleceń." << endl;
        return;
    }
    
    for (const auto& pair : _commandMap) {
        AbstractInterp4Command* pCmd = pair.second->CreateCmd();
        if (pCmd) {
            cout << "\nPolecenie: " << pair.first << endl;
            pCmd->PrintSyntax();
            delete pCmd;
        }
    }
    
    cout << endl;
}