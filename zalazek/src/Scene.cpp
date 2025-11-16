#include "Scene.hh"
#include <iostream>
#include <sstream>

using namespace std;

AbstractMobileObj* Scene::FindMobileObj(const char* sName) {
    if (!sName) return nullptr;
    
    auto it = _objects.find(sName);
    
    if (it != _objects.end()) {
        return it->second.get();  // Zwróć surowy wskaźnik
    }
    
    return nullptr;
}

void Scene::AddMobileObj(AbstractMobileObj* pMobObj) {
    if (!pMobObj) {
        cerr << "!!! Błąd: Próba dodania nullptr do sceny!" << endl;
        return;
    }
    
    string name = pMobObj->GetName();
    
    // Sprawdź czy obiekt o tej nazwie już istnieje
    if (_objects.find(name) != _objects.end()) {
        cerr << "!!! Ostrzeżenie: Obiekt '" << name << "' już istnieje. Zastępuję." << endl;
    }
    
    // Dodaj obiekt do mapy (unique_ptr przejmuje własność)
    _objects[name] = unique_ptr<MobileObj>(dynamic_cast<MobileObj*>(pMobObj));
    
    cout << "  Dodano obiekt do sceny: " << name << endl;
}

void Scene::PrintObjects() const {
    cout << "\n=== OBIEKTY NA SCENIE ===" << endl;
    cout << "Liczba obiektów: " << _objects.size() << endl;
    
    for (const auto& pair : _objects) {
        const MobileObj* obj = pair.second.get();
        cout << "  [" << obj->GetName() << "]" << endl;
        cout << "    Pozycja: " << obj->GetPositoin_m() << endl;
        cout << "    Kąty: Roll=" << obj->GetAng_Roll_deg() 
             << "Pitch=" << obj->GetAng_Pitch_deg()
             << "Yaw=" << obj->GetAng_Yaw_deg() << "°" << endl;
    }
    cout << "========================\n" << endl;
}

std::string Scene::GenerateUpdateAllCmd() const {
    std::ostringstream oss;
    
    for (const auto& pair : _objects) {
        oss << pair.second->GenerateUpdateCmd();
    }
    
    return oss.str();
}