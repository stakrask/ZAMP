#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "AbstractInterp4Command.hh"
#include "Preprocessor.hh"
#include "LibInterface.hh"

using namespace std;

int main()
{
  // Przetwarzanie pliku plik_test.cmd przez preprocesor
  const string preprocessedOutput = RunPreprocessor("plik_test.cmd");
  
  if (!preprocessedOutput.empty()) {
    cout << "=== Wynik preprocesora ===" << endl;
    cout << preprocessedOutput << endl;
    cout << "=========================" << endl << endl;
  }
  
  // Lista wtyczek do załadowania
  vector<string> libraries = {
    "libs/libInterp4Move.so",
    "libs/libInterp4Set.so",
    "libs/libInterp4Rotate.so",
    "libs/libInterp4Pause.so"
  };
  
  // Przetwarzanie każdej wtyczki
  for (const auto& libPath : libraries) {
    cout << "========================================" << endl;
    cout << "Ładowanie biblioteki: " << libPath << endl;
    cout << "========================================" << endl;
    
    LibInterface libInterface;
    
    if (!libInterface.LoadLibrary(libPath)) {
      cerr << "!!! Błąd: Nie udało się załadować " << libPath << endl;
      cout << endl;
      continue;
    }
    
    // Tworzenie instancji komendy
    AbstractInterp4Command *pCmd = libInterface.CreateCmd();
    
    if (!pCmd) {
      cerr << "!!! Błąd: Nie udało się utworzyć komendy z " << libPath << endl;
      cout << endl;
      continue;
    }
    
    // Wyświetlanie informacji o komendzie
    cout << "Nazwa komendy: " << pCmd->GetCmdName() << endl;
    cout << endl;
    
    cout << "Składnia:" << endl;
    pCmd->PrintSyntax();
    cout << endl;
    
    cout << "Przykładowe wywołanie:" << endl;
    pCmd->PrintCmd();
    cout << endl;
    
    delete pCmd;
  }
  
  return 0;
}