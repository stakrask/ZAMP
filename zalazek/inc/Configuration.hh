#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <string>
#include <vector>
#include "Vector3D.hh"

/*!
 * \file
 * \brief Definicja struktury konfiguracji sceny
 */

/*!
 * \brief Parametry pojedynczego obiektu Cube
 */
struct CubeParams {
    std::string name;          ///< Pełna kwalifikowana nazwa (np. "Podstawa.Ramie1")
    Vector3D shift;            ///< Wektor przesunięcia Tshift (domyślnie 0,0,0)
    Vector3D scale;            ///< Wektor skali S (domyślnie 1,1,1)
    Vector3D rotXYZ_deg;       ///< Kąty rotacji Roll-Pitch-Yaw w stopniach (domyślnie 0,0,0)
    Vector3D trans_m;          ///< Wektor translacji Ttrans w metrach (domyślnie 0,0,0)
    Vector3D rgb;              ///< Kolor RGB (domyślnie 128,128,128)
    
    /*!
     * \brief Konstruktor z wartościami domyślnymi
     */
    CubeParams() {
        shift = Vector3D();
        scale[0] = scale[1] = scale[2] = 1.0;
        rotXYZ_deg = Vector3D();
        trans_m = Vector3D();
        rgb[0] = rgb[1] = rgb[2] = 128.0;
    }
};

/*!
 * \brief Klasa przechowująca konfigurację całej sceny
 */
class Configuration {
private:
    std::vector<std::string> _libraries;  ///< Lista ścieżek do bibliotek wtyczek
    std::vector<CubeParams> _cubes;       ///< Lista parametrów obiektów Cube
    
public:
    /*!
     * \brief Konstruktor domyślny
     */
    Configuration() = default;
    
    /*!
     * \brief Dodaje ścieżkę do biblioteki wtyczki
     */
    void AddLibrary(const std::string& libPath) {
        _libraries.push_back(libPath);
    }
    
    /*!
     * \brief Dodaje obiekt Cube do konfiguracji
     */
    void AddCube(const CubeParams& cube) {
        _cubes.push_back(cube);
    }
    
    /*!
     * \brief Zwraca listę bibliotek
     */
    const std::vector<std::string>& GetLibraries() const {
        return _libraries;
    }
    
    /*!
     * \brief Zwraca listę obiektów Cube
     */
    const std::vector<CubeParams>& GetCubes() const {
        return _cubes;
    }
    
    /*!
     * \brief Wyświetla podsumowanie konfiguracji
     */
    void PrintSummary() const;

    /*!
     * \brief Generuje polecenie AddObj dla danego obiektu Cube
     * \param[in] cube - parametry obiektu
     * \return String zawierający polecenie AddObj
     */
    static std::string GenerateAddObjCommand(const CubeParams& cube);
};

#endif