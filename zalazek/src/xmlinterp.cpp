#include <xercesc/util/PlatformUtils.hpp>
#include "xmlinterp.hh"
#include <cassert>
#include <sstream>
#include <cstdlib>
#include <iostream>

using namespace std;

/*!
 * Konstruktor klasy. Inicjalizuje referencję do obiektu Configuration.
 */
XMLInterp4Config::XMLInterp4Config(Configuration &rConfig)
    : _rConfig(rConfig)
{
}

/*!
 * Metoda wywoływana jest bezpośrednio przed rozpoczęciem
 * przetwarzania dokumentu XML.
 */
void XMLInterp4Config::startDocument()
{
    cout << "Rozpoczęcie przetwarzania dokumentu XML." << endl;
}

/*!
 * Metoda wywoływana jest bezpośrednio po zakończeniu
 * przetwarzania dokumentu XML.
 */
void XMLInterp4Config::endDocument()
{
    cout << "Koniec przetwarzania dokumentu XML." << endl;
}

/*!
 * Pomocnicza funkcja do parsowania wektora 3D z napisu
 * \param[in] sValue - napis zawierający 3 liczby oddzielone spacjami
 * \param[out] vec - wektor, do którego zapisane zostaną wartości
 * \return true jeśli parsowanie się powiodło
 */
bool ParseVector3D(const char* sValue, Vector3D& vec)
{
    istringstream iss(sValue);
    double x, y, z;
    
    iss >> x >> y >> z;
    
    if (iss.fail()) {
        return false;
    }
    
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    
    return true;
}

/*!
 * Analizuje atrybuty elementu XML "Lib" i dodaje bibliotekę do konfiguracji.
 * \param[in] rAttrs - atrybuty elementu XML "Lib".
 */
void XMLInterp4Config::ProcessLibAttrs(const xercesc::Attributes &rAttrs)
{
    if (rAttrs.getLength() != 1) {
        cerr << "!!! Błąd: Zła ilość atrybutów dla \"Lib\"" << endl;
        return;
    }

    char* sParamName = xercesc::XMLString::transcode(rAttrs.getQName(0));

    if (strcmp(sParamName, "Name")) {
        cerr << "!!! Błąd: Zła nazwa atrybutu dla Lib (oczekiwano 'Name')" << endl;
        xercesc::XMLString::release(&sParamName);
        return;
    }

    XMLSize_t Size = 0;
    char* sLibName = xercesc::XMLString::transcode(rAttrs.getValue(Size));

    cout << "  Dodawanie biblioteki: " << sLibName << endl;
    
    // Dodaj bibliotekę do konfiguracji
    _rConfig.AddLibrary(string(sLibName));

    xercesc::XMLString::release(&sParamName);
    xercesc::XMLString::release(&sLibName);
}

/*!
 * Analizuje atrybuty elementu XML "Cube" i tworzy obiekt CubeParams.
 * \param[in] rAttrs - atrybuty elementu XML "Cube".
 */
void XMLInterp4Config::ProcessCubeAttrs(const xercesc::Attributes &rAttrs)
{
    if (rAttrs.getLength() < 1) {
        cerr << "!!! Błąd: Brak atrybutu 'Name' dla \"Cube\"" << endl;
        return;
    }

    CubeParams cube;  // Utworzenie obiektu z domyślnymi wartościami

    // Przetwarzanie wszystkich atrybutów
    for (XMLSize_t i = 0; i < rAttrs.getLength(); ++i) {
        char* sAttrName = xercesc::XMLString::transcode(rAttrs.getQName(i));
        char* sAttrValue = xercesc::XMLString::transcode(rAttrs.getValue(i));

        if (strcmp(sAttrName, "Name") == 0) {
            cube.name = sAttrValue;
            cout << "  Cube: " << cube.name << endl;
        }
        else if (strcmp(sAttrName, "Shift") == 0) {
            if (!ParseVector3D(sAttrValue, cube.shift)) {
                cerr << "!!! Błąd parsowania atrybutu Shift" << endl;
            }
        }
        else if (strcmp(sAttrName, "Scale") == 0) {
            if (!ParseVector3D(sAttrValue, cube.scale)) {
                cerr << "!!! Błąd parsowania atrybutu Scale" << endl;
            }
        }
        else if (strcmp(sAttrName, "RotXYZ_deg") == 0) {
            if (!ParseVector3D(sAttrValue, cube.rotXYZ_deg)) {
                cerr << "!!! Błąd parsowania atrybutu RotXYZ_deg" << endl;
            }
        }
        else if (strcmp(sAttrName, "Trans_m") == 0) {
            if (!ParseVector3D(sAttrValue, cube.trans_m)) {
                cerr << "!!! Błąd parsowania atrybutu Trans_m" << endl;
            }
        }
        else if (strcmp(sAttrName, "RGB") == 0) {
            if (!ParseVector3D(sAttrValue, cube.rgb)) {
                cerr << "!!! Błąd parsowania atrybutu RGB" << endl;
            }
        }
        else {
            cerr << "!!! Ostrzeżenie: Nieznany atrybut '" << sAttrName << "'" << endl;
        }

        xercesc::XMLString::release(&sAttrName);
        xercesc::XMLString::release(&sAttrValue);
    }

    // Dodajemy obiekt Cube do konfiguracji
    _rConfig.AddCube(cube);
}

/*!
 * Wykonuje operacje związane z wystąpieniem danego elementu XML.
 * \param[in] rElemName - nazwa elementu XML.
 * \param[in] rAttrs - atrybuty napotkanego elementu XML.
 */
void XMLInterp4Config::WhenStartElement(const std::string &rElemName,
                                        const xercesc::Attributes &rAttrs)
{
    if (rElemName == "Lib") {
        ProcessLibAttrs(rAttrs);
        return;
    }

    if (rElemName == "Cube") {
        ProcessCubeAttrs(rAttrs);
        return;
    }

    // Ignoruj inne elementy (Config, Plugins, Objects)
}

/*
 * Metoda wywoływana po napotkaniu nowego elementu XML.
 */
void XMLInterp4Config::startElement(const XMLCh *const pURI,
                                    const XMLCh *const pLocalName,
                                    const XMLCh *const pQName,
                                    const xercesc::Attributes &rAttrs)
{
    char *sElemName = xercesc::XMLString::transcode(pLocalName);
    
    if (strcmp(sElemName, "Config") != 0 && 
        strcmp(sElemName, "Plugins") != 0 && 
        strcmp(sElemName, "Objects") != 0) {
        cout << "+++ Element: " << sElemName << endl;
    }

    WhenStartElement(sElemName, rAttrs);

    xercesc::XMLString::release(&sElemName);
}

/*
 * Metoda wywoływana po zakończeniu elementu XML.
 */
void XMLInterp4Config::endElement(const XMLCh *const pURI,
                                  const XMLCh *const pLocalName,
                                  const XMLCh *const pQName)
{
    
}

/*
 * Obsługa błędu fatalnego
 */
void XMLInterp4Config::fatalError(const xercesc::SAXParseException &rException)
{
    char *sMessage = xercesc::XMLString::transcode(rException.getMessage());
    char *sSystemId = xercesc::XMLString::transcode(rException.getSystemId());

    cerr << "!!! Błąd fatalny!" << endl
         << "Plik:  " << sSystemId << endl
         << "Linia: " << rException.getLineNumber() << endl
         << "Kolumna: " << rException.getColumnNumber() << endl
         << "Informacja: " << sMessage
         << endl;

    xercesc::XMLString::release(&sMessage);
    xercesc::XMLString::release(&sSystemId);
}
/*
 * Obsługa błędu
 */
void XMLInterp4Config::error(const xercesc::SAXParseException &rException)
{
    char *sMessage = xercesc::XMLString::transcode(rException.getMessage());
    
    cerr << "!!! Błąd: " << sMessage << endl;
    
    xercesc::XMLString::release(&sMessage);
}
/*
 * Obsługa ostrzeżenia
 */
void XMLInterp4Config::warning(const xercesc::SAXParseException &rException)
{
    char *sMessage = xercesc::XMLString::transcode(rException.getMessage());
    
    cerr << "!!! Ostrzeżenie: " << sMessage << endl;
    
    xercesc::XMLString::release(&sMessage);
}