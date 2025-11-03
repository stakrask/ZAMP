#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Preprocessor.hh"
#include "CommandRegistry.hh"

using namespace std;

int main()
{
  cout << "=== Interpreter poleceń - Etap 1 ===" << endl << endl;
  
  // Tworzenie rejestru poleceń
  CommandRegistry registry;
  
  // Lista wtyczek do załadowania
  vector<string> libraries = {
    "libs/libInterp4Move.so",
    "libs/libInterp4Set.so",
    "libs/libInterp4Rotate.so",
    "libs/libInterp4Pause.so"
  };
  
  // Rejestracja wszystkich wtyczek
  cout << "=== Rejestracja wtyczek ===" << endl;
  for (const auto& libPath : libraries) {
    if (!registry.RegisterCommand(libPath)) {
      cerr << "!!! Ostrzeżenie: Problem z załadowaniem " << libPath << endl;
    }
  }
  cout << endl;
  
  // Wyświetlenie dostępnych poleceń
  registry.PrintAvailableCommands();
  
  // Przetwarzanie pliku plik_test.cmd przez preprocesor
  const string inputFile = "plik_test.cmd";
  cout << "=== Przetwarzanie pliku: " << inputFile << " ===" << endl;
  
  const string preprocessedOutput = RunPreprocessor(inputFile.c_str());
  
  if (preprocessedOutput.empty()) {
    cerr << "!!! Błąd: Nie udało się przetworzyć pliku przez preprocesor." << endl;
    return 1;
  }
  
  cout << "\n=== Zawartość po przetworzeniu przez preprocesor ===" << endl;
  cout << preprocessedOutput << endl;
  
  // Przetwarzanie poleceń
  istringstream cmdStream(preprocessedOutput);
  
  if (!registry.ProcessCommands(cmdStream)) {
    cerr << "\n!!! Ostrzeżenie: Niektóre polecenia nie zostały poprawnie przetworzone." << endl;
  }
  
  cout << "\n=== Program zakończony ===" << endl;
  
  return 0;
}