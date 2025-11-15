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
    Configuration config;
    
    const string configFile = "config/config.xml";
    
    if (!ReadXMLConfiguration(configFile.c_str(), config)) {
        cerr << "!!! Błąd: Nie udało się wczytać konfiguracji z pliku XML." << endl;
        return 1;
    }

    CommandRegistry registry;
    
    for (const auto& libPath : config.GetLibraries()) {
        string fullPath = libPath;
        if (fullPath.find('/') == string::npos) {
            fullPath = "libs/" + libPath;
        }
        
        if (!registry.RegisterCommand(fullPath)) {
            cerr << "!!! Ostrzeżenie: Problem z załadowaniem " << fullPath << endl;
        }
    }

    const string inputFile = "plik_test.cmd";
    
    const string preprocessedOutput = RunPreprocessor(inputFile.c_str());
    
    if (preprocessedOutput.empty()) {
        cerr << "!!! Błąd: Nie udało się przetworzyć pliku przez preprocesor." << endl;
        return 1;
    }
    
    istringstream cmdStream(preprocessedOutput);
    
    if (!registry.ProcessCommands(cmdStream)) {
        cerr << "!!! Ostrzeżenie: Niektóre polecenia nie zostały poprawnie przetworzone." << endl;
    }

    return 0;
}