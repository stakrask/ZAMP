#include "Configuration.hh"
#include <iostream>
#include <sstream>

using namespace std;

void Configuration::PrintSummary() const
{
    cout << "\nPODSUMOWANIE KONFIG" << endl;

    cout << "\nWtyczki (" << _libraries.size() << "):" << endl;
    for (const auto &lib : _libraries)
    {
        cout << "  - " << lib << endl;
    }

    cout << "\nObiekty Cube (" << _cubes.size() << "):" << endl;
    for (const auto &cube : _cubes)
    {
        cout << "  [" << cube.name << "]" << endl;
        cout << "    Shift:      " << cube.shift << endl;
        cout << "    Scale:      " << cube.scale << endl;
        cout << "    RotXYZ_deg: " << cube.rotXYZ_deg << endl;
        cout << "    Trans_m:    " << cube.trans_m << endl;
        cout << "    RGB:        " << cube.rgb << endl;
    }
    cout << endl;
}

std::string Configuration::GenerateAddObjCommand(const CubeParams &cube)
{
    std::ostringstream oss;

    oss << "AddObj Name=" << cube.name;
    oss << " Shift=(" << cube.shift[0] << "," << cube.shift[1] << "," << cube.shift[2] << ")";
    oss << " Scale=(" << cube.scale[0] << "," << cube.scale[1] << "," << cube.scale[2] << ")";
    oss << " RotXYZ_deg=(" << cube.rotXYZ_deg[0] << "," << cube.rotXYZ_deg[1] << "," << cube.rotXYZ_deg[2] << ")";
    oss << " Trans_m=(" << cube.trans_m[0] << "," << cube.trans_m[1] << "," << cube.trans_m[2] << ")";
    oss << " RGB=(" << (int)cube.rgb[0] << "," << (int)cube.rgb[1] << "," << (int)cube.rgb[2] << ")";
    oss << "\n";

    return oss.str();
}