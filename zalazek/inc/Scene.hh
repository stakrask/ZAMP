#ifndef SCENE_HH
#define SCENE_HH

#include "AbstractScene.hh"
#include "MobileObj.hh"
#include <map>
#include <string>
#include <memory>

/*!
 * \brief Klasa reprezentująca scenę 3D z obiektami mobilnymi
 * 
 * Scena przechowuje kolekcję obiektów mobilnych i umożliwia
 * ich wyszukiwanie po pełnej kwalifikowanej nazwie.
 */
class Scene : public AbstractScene {
private:
    /*!
     * \brief Mapa obiektów: klucz = nazwa, wartość = wskaźnik do obiektu
     * 
     * Używamy std::map dla szybkiego wyszukiwania po nazwie.
     * Używamy unique_ptr dla automatycznego zarządzania pamięcią.
     */
    std::map<std::string, std::unique_ptr<MobileObj>> _objects;
    
public:
    /*!
     * \brief Konstruktor domyślny
     */
    Scene() = default;
    
    /*!
     * \brief Destruktor - automatycznie usuwa wszystkie obiekty
     */
    virtual ~Scene() = default;
    
    // ===== Implementacja interfejsu AbstractScene =====
    
    /*!
     * \brief Wyszukuje obiekt po pełnej kwalifikowanej nazwie
     * 
     * \param[in] sName - nazwa obiektu (np. "Podstawa.Ramie1")
     * \return Wskaźnik do obiektu lub nullptr jeśli nie znaleziono
     */
    virtual AbstractMobileObj* FindMobileObj(const char* sName) override;
    
    /*!
     * \brief Dodaje obiekt do sceny
     * 
     * UWAGA: Scena przejmuje własność wskaźnika!
     * \param[in] pMobObj - wskaźnik do obiektu (zostanie zarządzany przez scenę)
     */
    virtual void AddMobileObj(AbstractMobileObj* pMobObj) override;
    
    // ===== Metody dodatkowe =====
    
    /*!
     * \brief Zwraca liczbę obiektów na scenie
     */
    size_t GetObjectCount() const { return _objects.size(); }
    
    /*!
     * \brief Wyświetla listę wszystkich obiektów na scenie
     */
    void PrintObjects() const;
    
    /*!
     * \brief Generuje polecenia UpdateObj dla wszystkich obiektów
     */
    std::string GenerateUpdateAllCmd() const;
};

#endif