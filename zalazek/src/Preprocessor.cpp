#include "Preprocessor.hh"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio>

std::string RunPreprocessor(const char* sFileName)
{
    std::string result;
    
    // Walidacja czy plik wejściowy istnieje
    std::ifstream testFile(sFileName);
    if (!testFile.good()) {
        std::cerr << "!!! Błąd: Nie istnieje plik o nazwie " << sFileName << std::endl;
        return result;
    }
    testFile.close();
    
    // Przygotowanie komendy preprocesora
    std::string command = "cpp -P ";
    command += sFileName;
    command += " 2>/dev/null";  // Ukryj stderr preprocesora
    
    // Otwarcie potoku do odczytu wyjścia preprocesora
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "!!! Błąd: Nie można uruchomić preprocesora (popen failed)" << std::endl;
        return result;
    }
    
    // Odczyt danych strumieniowo z potoku
    std::vector<char> buffer(4096);
    while (size_t bytesRead = fread(buffer.data(), sizeof(char), buffer.size(), pipe)) {
        result.append(buffer.data(), bytesRead);
        if (bytesRead < buffer.size()) {
            break;
        }
    }
    
    // Zamknięcie potoku i sprawdzenie kodu powrotu
    int returnCode = pclose(pipe);
    if (returnCode != 0) {
        std::cerr << "!!! Błąd: Preprocesor zakończył się z kodem: " << returnCode << std::endl;
        result.clear();  // Wyczyść wynik w przypadku błędu
        return result;
    }
    
    return result;
}