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
        _objMutex.lock();
        double result = _ang_Roll_deg;
        _objMutex.unlock();
        return result;
    }
    
    virtual double GetAng_Pitch_deg() const override {
        _objMutex.lock();
        double result = _ang_Pitch_deg;
        _objMutex.unlock();
        return result;
    }
    
    virtual double GetAng_Yaw_deg() const override {
        _objMutex.lock();
        double result = _ang_Yaw_deg;
        _objMutex.unlock();
        return result;
    }
    
    virtual void SetAng_Roll_deg(double ang) override {
        _objMutex.lock();
        _ang_Roll_deg = ang;
        _objMutex.unlock();
    }
    
    virtual void SetAng_Pitch_deg(double ang) override {
        _objMutex.lock();
        _ang_Pitch_deg = ang;
        _objMutex.unlock();
    }
    
    virtual void SetAng_Yaw_deg(double ang) override {
        _objMutex.lock();
        _ang_Yaw_deg = ang;
        _objMutex.unlock();
    }
    
    virtual const Vector3D& GetPositoin_m() const override {
        _objMutex.lock();
        const Vector3D& result = _position_m;
        _objMutex.unlock();
        return result;
    }
    
    virtual void SetPosition_m(const Vector3D& pos) override {
        _objMutex.lock();
        _position_m = pos;
        _objMutex.unlock();
    }
    
    virtual void SetName(const char* name) override {
        _objMutex.lock();
        _name = name;
        _objMutex.unlock();
    }
    
    virtual const std::string& GetName() const override {
        _objMutex.lock();
        const std::string& result = _name;
        _objMutex.unlock();
        return result;
    }
    
    /*!
     * \brief Zwraca parametry geometryczne obiektu
     */
    const Vector3D& GetShift() const {
        _objMutex.lock();
        const Vector3D& result = _shift;
        _objMutex.unlock();
        return result;
    }
    
    const Vector3D& GetScale() const {
        _objMutex.lock();
        const Vector3D& result = _scale;
        _objMutex.unlock();
        return result;
    }
    
    const Vector3D& GetRGB() const {
        _objMutex.lock();
        const Vector3D& result = _rgb;
        _objMutex.unlock();
        return result;
    }
    
    /*!
     * \brief Generuje polecenie UpdateObj dla tego obiektu 
     * 
     * Cała operacja jest atomowa - mutex zapewnia spójny snapshot stanu obiektu.
     */
    std::string GenerateUpdateCmd() const;
};

#endif