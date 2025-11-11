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
    
    cout << "\n=== Przetwarzanie poleceń ===" << endl;
    
    while (getline(rStrm, line)) {
        lineNumber++;
        
        // Pomiń puste linie
        if (line.empty()) {
            continue;
        }
        
        // Usuń białe znaki z początku
        size_t start = line.find_first_not_of(" \t\r\n");
        if (start == string::npos) {
            continue;
        }
        line = line.substr(start);
        
        // Pomiń komentarze (linie zaczynające się od #)
        if (line[0] == '#') {
            continue;
        }
        
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
        
        // UWAGA: Polecenie Pause NIE wymaga nazwy obiektu!
        string objName;
        
        if (cmdName != "Pause") {
            // Wczytaj nazwę obiektu (dla Set, Move, Rotate)
            lineStream >> objName;
            
            if (lineStream.fail() || objName.empty()) {
                cerr << "!!! Błąd w linii " << lineNumber 
                     << ": Brak nazwy obiektu dla polecenia '" << cmdName << "'" << endl;
                cout << "Oczekiwana składnia:" << endl;
                pCmd->PrintSyntax();
                allSuccess = false;
                delete pCmd;
                continue;
            }
            
            cout << "Obiekt: " << objName << endl;
        } else {
            objName = ""; // Pause nie używa nazwy obiektu
        }
        
        // Wczytaj parametry (po nazwie obiektu lub bezpośrednio dla Pause)
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
        if (!objName.empty()) {
            cout << cmdName << " " << objName << " ";
        }
        pCmd->PrintCmd();
        
        // TODO: W przyszłości tutaj będzie wywołanie:
        // pCmd->ExecCmd(scene, objName.c_str(), comChannel);
        
        delete pCmd;
    }
    
    cout << "\n=== Koniec przetwarzania ===" << endl;
      
    return allSuccess;
}

void CommandRegistry::PrintAvailableCommands() const {
    cout << "\n=== Dostępne polecenia ===" << endl;
    
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

//Sposób na implementację ProcessCommands bez przetwarzania linii po linii.

//StdIn >> Słowo
//pIter = KolekcjaWtyczek.find(Słowo),
//pIter -> ReadParams(StdIn);
//pIter -> StdIn>>NazwaObiektu>>Szybkość>>Dystans;
//return !StdIn.fail();
//char Tab[101];
//scanf("%100s",Tab);
//intRes=scanf("%d",&Zmienna);
//return intRes==1;
//Czytamy z tego co nam preprocesor przetworzy żeby nie było komentarzy ani makr

//To do:
//3. Przerobić commandregistry by korzystał z rozwiązania powyżej
//4. Uporządkować maina konfiguracjaXML->Ładowanie wtyczek->Plik CMD przetwarzany przez Preprocesor->CommandRegistryz->ReadParams w określonej wtyczce->PrintParams->ExecCmd    
//5. Uporządkować resztę kodu
//6. Przetestować całość
//7. Nauczyć się kodu oraz to co jakiego typu są zmienne przy mapie (iterator w kolekcji bibliotek, lepsza metoda by zwracało wskaźnik do obiektu polecenia)
