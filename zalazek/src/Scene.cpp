#include "Scene.hh"
#include <iostream>
#include <sstream>

using namespace std;

// Wyszukuje obiekt po pełnej kwalifikowanej nazwie
AbstractMobileObj* Scene::FindMobileObj(const char* sName) {
    if (!sName) return nullptr;
    
    // Lock mutex dla dostępu do mapy
    _sceneMutex.lock();
    
    auto it = _objects.find(sName);
    
    AbstractMobileObj* result = nullptr;
    if (it != _objects.end()) {
        result = it->second.get();  // Zwróć surowy wskaźnik
    }
    
    _sceneMutex.unlock();
    
    return result;
}

// Dodaje obiekt do sceny
void Scene::AddMobileObj(AbstractMobileObj* pMobObj) {
    if (!pMobObj) {
        cerr << "!!! Błąd: Próba dodania nullptr do sceny!" << endl;
        return;
    }
    
    string name = pMobObj->GetName();
    
    // Lock mutex dla modyfikacji mapy
    _sceneMutex.lock();
    
    // Sprawdź czy obiekt o tej nazwie już istnieje
    if (_objects.find(name) != _objects.end()) {
        cerr << "!!! Ostrzeżenie: Obiekt '" << name << "' już istnieje. Zastępuję." << endl;
    }
    
    // Dodaj obiekt do mapy (unique_ptr przejmuje własność)
    _objects[name] = unique_ptr<MobileObj>(dynamic_cast<MobileObj*>(pMobObj));
    
    _sceneMutex.unlock();
    
    cout << "Dodano obiekt do sceny: " << name << endl;
}

// Wyświetla listę wszystkich obiektów na scenie
void Scene::PrintObjects() const {
    // Lock mutex dla iteracji po mapie
    _sceneMutex.lock();
    
    cout << "\n=== OBIEKTY NA SCENIE ===" << endl;
    cout << "Liczba obiektów: " << _objects.size() << endl;
    
    for (const auto& pair : _objects) {
        const MobileObj* obj = pair.second.get();
        // GetName(), GetPositoin_m(), GetAng_*() są już thread-safe w MobileObj
        cout << "  [" << obj->GetName() << "]" << endl;
        cout << "    Pozycja: " << obj->GetPositoin_m() << endl;
        cout << "    Kąty: Roll=" << obj->GetAng_Roll_deg() 
             << "° Pitch=" << obj->GetAng_Pitch_deg()
             << "° Yaw=" << obj->GetAng_Yaw_deg() << "°" << endl;
    }
    
    _sceneMutex.unlock();
}

// Generuje polecenia UpdateObj dla wszystkich obiektów
std::string Scene::GenerateUpdateAllCmd() const {
    // Lock mutex dla iteracji po mapie
    _sceneMutex.lock();
    
    std::ostringstream oss;
    
    for (const auto& pair : _objects) {
        oss << pair.second->GenerateUpdateCmd();
    }
    
    _sceneMutex.unlock();
    
    return oss.str();
}