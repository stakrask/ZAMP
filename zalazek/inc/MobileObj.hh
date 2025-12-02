#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH

#include "AbstractMobileObj.hh"
#include "Configuration.hh"
#include <string>
#include <mutex>

/*!
 * \brief Klasa reprezentująca pojedynczy obiekt mobilny na scenie (THREAD-SAFE)
 * 
 * Obiekt przechowuje swoją pozycję, orientację (kąty Roll-Pitch-Yaw),
 * oraz parametry geometryczne (skala, przesunięcie, kolor).
 * 
 * BEZPIECZEŃSTWO WIELOWĄTKOWE:
 * Każdy obiekt ma własny mutex, który chroni jego stan przed race conditions
 * podczas jednoczesnych modyfikacji z wielu wątków.
 */
class MobileObj : public AbstractMobileObj {
private:
    std::string _name;        ///< Pełna kwalifikowana nazwa (np. "Podstawa.Ramie1")
    Vector3D _position_m;     ///< Pozycja w przestrzeni [m]
    double _ang_Roll_deg;     ///< Kąt Roll (obrót wokół OX) [stopnie]
    double _ang_Pitch_deg;    ///< Kąt Pitch (obrót wokół OY) [stopnie]
    double _ang_Yaw_deg;      ///< Kąt Yaw (obrót wokół OZ) [stopnie]
    
    // Parametry geometryczne z konfiguracji
    Vector3D _shift;          ///< Przesunięcie lokalne T_shift
    Vector3D _scale;          ///< Skala S
    Vector3D _rgb;            ///< Kolor RGB
    
    mutable std::mutex _objMutex;  ///< Mutex chroniący stan obiektu
    
public:
    /*!
     * \brief Konstruktor z parametrami z konfiguracji
     */
    MobileObj(const CubeParams& params);
    
    /*!
     * \brief Destruktor
     */
    virtual ~MobileObj() {}
    
    virtual double GetAng_Roll_deg() const override {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _ang_Roll_deg;
    }
    
    virtual double GetAng_Pitch_deg() const override {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _ang_Pitch_deg;
    }
    
    virtual double GetAng_Yaw_deg() const override {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _ang_Yaw_deg;
    }
    
    virtual void SetAng_Roll_deg(double ang) override {
        std::lock_guard<std::mutex> lock(_objMutex);
        _ang_Roll_deg = ang;
    }
    
    virtual void SetAng_Pitch_deg(double ang) override {
        std::lock_guard<std::mutex> lock(_objMutex);
        _ang_Pitch_deg = ang;
    }
    
    virtual void SetAng_Yaw_deg(double ang) override {
        std::lock_guard<std::mutex> lock(_objMutex);
        _ang_Yaw_deg = ang;
    }
    
    virtual const Vector3D& GetPositoin_m() const override {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _position_m;
    }
    
    virtual void SetPosition_m(const Vector3D& pos) override {
        std::lock_guard<std::mutex> lock(_objMutex);
        _position_m = pos;
    }
    
    virtual void SetName(const char* name) override {
        std::lock_guard<std::mutex> lock(_objMutex);
        _name = name;
    }
    
    virtual const std::string& GetName() const override {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _name;
    }
    
    /*!
     * \brief Zwraca parametry geometryczne obiektu
     */
    const Vector3D& GetShift() const {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _shift;
    }
    
    const Vector3D& GetScale() const {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _scale;
    }
    
    const Vector3D& GetRGB() const {
        std::lock_guard<std::mutex> lock(_objMutex);
        return _rgb;
    }
    
    /*!
     * \brief Generuje polecenie UpdateObj dla tego obiektu 
     * 
     * Cała operacja jest atomowa - mutex zapewnia spójny snapshot stanu obiektu.
     */
    std::string GenerateUpdateCmd() const;
};

#endif