#include <iostream>
#include <sstream>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

#include "Preprocessor.hh"
#include "CommandRegistry.hh"
#include "Configuration.hh"
#include "xmlinterp.hh"
#include "Connection.hh"
#include "Scene.hh"
#include "MobileObj.hh"

using namespace std;
using namespace xercesc;

bool ReadXMLConfiguration(const char* sFileName, Configuration &rConfig)
{
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cerr << "!!! Błąd podczas inicjalizacji parsera XML:" << endl;
        cerr << "    " << message << endl;
        XMLString::release(&message);
        return false;
    }

    SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

    pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
    pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    pParser->setFeature(XMLUni::fgXercesDynamic, false);
    pParser->setFeature(XMLUni::fgXercesSchema, true);
    pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
    pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

    DefaultHandler* pHandler = new XMLInterp4Config(rConfig);
    pParser->setContentHandler(pHandler);
    pParser->setErrorHandler(pHandler);

    try {
        if (!pParser->loadGrammar("config/config.xsd",
                                  Grammar::SchemaGrammarType, true)) {
            cerr << "!!! Błąd: Plik config/config.xsd nie może zostać wczytany." << endl;
            delete pParser;
            delete pHandler;
            return false;
        }
        
        pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);
        pParser->parse(sFileName);
    }
    catch (const XMLException& Exception) {
        char* sMessage = XMLString::transcode(Exception.getMessage());
        cerr << "!!! Wyjątek XML:" << endl
             << "    " << sMessage << endl;
        XMLString::release(&sMessage);
        delete pParser;
        delete pHandler;
        return false;
    }
    catch (const SAXParseException& Exception) {
        char* sMessage = XMLString::transcode(Exception.getMessage());
        char* sSystemId = XMLString::transcode(Exception.getSystemId());

        cerr << "!!! Błąd parsowania XML!" << endl
             << "    Plik:  " << sSystemId << endl
             << "   Linia: " << Exception.getLineNumber() << endl
             << " Kolumna: " << Exception.getColumnNumber() << endl
             << " Informacja: " << sMessage << endl;

        XMLString::release(&sMessage);
        XMLString::release(&sSystemId);
        delete pParser;
        delete pHandler;
        return false;
    }
    catch (...) {
        cerr << "!!! Nieoczekiwany wyjątek podczas parsowania XML!" << endl;
        delete pParser;
        delete pHandler;
        return false;
    }

    delete pParser;
    delete pHandler;
    
    XMLPlatformUtils::Terminate();
    
    return true;
}

int main(int argc, char* argv[])
{
    // ========== 1. WCZYTANIE KONFIGURACJI XML ==========
    Configuration config;
    const string configFile = "config/config.xml";
    
    cout << "Wczytywanie konfiguracji z pliku: " << configFile << endl;
    if (!ReadXMLConfiguration(configFile.c_str(), config)) {
        cerr << "!!! Błąd: Nie udało się wczytać konfiguracji z pliku XML." << endl;
        return 1;
    }
    cout << "Konfiguracja wczytana pomyślnie." << endl << endl;

    // ========== 2. UTWORZENIE SCENY ==========
    Scene scene;
    cout << "Scena utworzona." << endl << endl;

    // ========== 3. REJESTRACJA WTYCZEK ==========
    CommandRegistry registry;
    
    cout << "Rejestrowanie wtyczek..." << endl;
    for (const auto& libPath : config.GetLibraries()) {
        string fullPath = libPath;
        if (fullPath.find('/') == string::npos) {
            fullPath = "libs/" + libPath;
        }
        
        if (!registry.RegisterCommand(fullPath)) {
            cerr << "!!! Ostrzeżenie: Problem z załadowaniem " << fullPath << endl;
        }
    }
    cout << "Wtyczki zarejestrowane." << endl << endl;

    // ========== 4. NAWIĄZANIE POŁĄCZENIA Z SERWEREM GRAFICZNYM ==========
    int socket = -1;
    
    if (!OpenConnection(socket)) {
        cerr << "!!! Błąd: Nie można nawiązać połączenia z serwerem graficznym." << endl;
        return 1;
    }
    
    // ========== 5. WYCZYSZCZENIE SCENY NA SERWERZE ==========
    cout << "Wysyłanie polecenia Clear..." << endl;
    if (Send(socket, "Clear\n") == 0) {
        cout << "Polecenie Clear wysłane." << endl;
    } else {
        cerr << "!!! Błąd wysyłania polecenia Clear." << endl;
    }
    
    cout << endl;

    // ========== 6. WYSŁANIE OBIEKTÓW DO SERWERA I DODANIE DO SCENY ==========
    cout << "Wysyłanie obiektów do serwera graficznego..." << endl;
    for (const auto& cube : config.GetCubes()) {
        // Utwórz obiekt na podstawie parametrów z konfiguracji
        MobileObj* pObj = new MobileObj(cube);
        
        // Dodaj obiekt do sceny (scena przejmuje własność wskaźnika)
        scene.AddMobileObj(pObj);
        
        // Wygeneruj polecenie AddObj
        std::string cmd = Configuration::GenerateAddObjCommand(cube);
        cout << "Wysyłam: " << cmd;
        
        // Wyślij polecenie do serwera
        if (Send(socket, cmd.c_str()) != 0) {
            cerr << "!!! Błąd wysyłania obiektu: " << cube.name << endl;
        }
    }
    cout << "Obiekty wysłane." << endl << endl;

    // ========== 7. WYŚWIETLENIE PODSUMOWANIA SCENY ==========
    scene.PrintObjects();

    // ========== 8. PRZETWARZANIE PLIKU POLECEŃ ==========
    const string inputFile = "plik_test.cmd";
    
    cout << "Przetwarzanie pliku poleceń: " << inputFile << endl;
    const string preprocessedOutput = RunPreprocessor(inputFile.c_str());
    
    if (preprocessedOutput.empty()) {
        cerr << "!!! Błąd: Nie udało się przetworzyć pliku przez preprocesor." << endl;
        CloseConnection(socket);
        return 1;
    }
    
    istringstream cmdStream(preprocessedOutput);
    
    if (!registry.ProcessCommands(cmdStream)) {
        cerr << "!!! Ostrzeżenie: Niektóre polecenia nie zostały poprawnie przetworzone." << endl;
    }

    cout << endl;

    // ========== 9. ZAMKNIĘCIE POŁĄCZENIA ==========
    cout << "Zamykanie połączenia z serwerem..." << endl;
    CloseConnection(socket);
    cout << "Program zakończony pomyślnie." << endl;
    
    return 0;
}