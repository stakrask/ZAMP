#include <iostream>
#include <cassert>
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
  
  // Ładowanie biblioteki przez LibInterface
  LibInterface libInterface;
  
  if (!libInterface.LoadLibrary("libInterp4Move.so")) {
    cerr << "!!! Błąd: Nie udało się załadować libInterp4Move.so" << endl;
    return 1;
  }
  
  // Tworzenie instancji komendy
  AbstractInterp4Command *pCmd = libInterface.CreateCmd();
  
  if (!pCmd) {
    cerr << "!!! Błąd: Nie udało się utworzyć komendy" << endl;
    return 1;
  }
  
  // Wyświetlanie informacji o komendzie
  cout << "Nazwa komendy: " << pCmd->GetCmdName() << endl;
  cout << endl;
  
  cout << "Składnia:" << endl;
  pCmd->PrintSyntax();
  cout << endl;
  
  cout << "Komenda:" << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;
  
  return 0;
}