#include "MobileObj.hh"
#include <sstream>
#include <iomanip>

// Konstruktor z parametrami z konfiguracji
MobileObj::MobileObj(const CubeParams& params)
    : _name(params.name)
    , _position_m(params.trans_m)
    , _ang_Roll_deg(params.rotXYZ_deg[0])
    , _ang_Pitch_deg(params.rotXYZ_deg[1])
    , _ang_Yaw_deg(params.rotXYZ_deg[2])
    , _shift(params.shift)
    , _scale(params.scale)
    , _rgb(params.rgb)
{
}

// Generuje polecenie UpdateObj dla tego obiektu
std::string MobileObj::GenerateUpdateCmd() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3); // Ustawienie precyzji dla liczb zmiennoprzecinkowych
    
    oss << "UpdateObj Name=" << _name;
    oss << "Shift=(" << _shift[0] << "," << _shift[1] << "," << _shift[2] << ")";
    oss << "Scale=(" << _scale[0] << "," << _scale[1] << "," << _scale[2] << ")";
    oss << "RotXYZ_deg=(" << _ang_Roll_deg << "," << _ang_Pitch_deg << "," << _ang_Yaw_deg << ")";
    oss << "Trans_m=(" << _position_m[0] << "," << _position_m[1] << "," << _position_m[2] << ")";
    oss << "RGB=(" << (int)_rgb[0] << "," << (int)_rgb[1] << "," << (int)_rgb[2] << ")";
    oss << "\n";
    
    return oss.str();
}