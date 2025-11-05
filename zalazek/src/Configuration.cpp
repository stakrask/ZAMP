#include "Configuration.hh"
#include <iostream>

using namespace std;

void Configuration::PrintSummary() const {
    cout << "\nPODSUMOWANIE KONFIG" << endl;
    
    cout << "\nWtyczki (" << _libraries.size() << "):" << endl;
    for (const auto& lib : _libraries) {
        cout << "  - " << lib << endl;
    }
    
    cout << "\nObiekty Cube (" << _cubes.size() << "):" << endl;
    for (const auto& cube : _cubes) {
        cout << "  [" << cube.name << "]" << endl;
        cout << "    Shift:      " << cube.shift << endl;
        cout << "    Scale:      " << cube.scale << endl;
        cout << "    RotXYZ_deg: " << cube.rotXYZ_deg << endl;
        cout << "    Trans_m:    " << cube.trans_m << endl;
        cout << "    RGB:        " << cube.rgb << endl;
    }
    cout << endl;
}