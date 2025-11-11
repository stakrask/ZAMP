#include <iostream>
#include "Interp4Set.hh"

using std::cout;
using std::endl;
using std::cerr;

extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}

/*!
 * \brief Tworzy instancję polecenia Set
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}

/*!
 * \brief Konstruktor
 */
Interp4Set::Interp4Set(): _Pos_X(0), _Pos_Y(0), _Pos_Z(0), 
                          _Angle_OX_deg(0), _Angle_OY_deg(0), _Angle_OZ_deg(0)
{}

/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Set::PrintCmd() const
{
  cout << GetCmdName() << " X=" << _Pos_X << " Y=" << _Pos_Y << " Z=" << _Pos_Z
       << " OX=" << _Angle_OX_deg << " OY=" << _Angle_OY_deg << " OZ=" << _Angle_OZ_deg << "stopni" << endl;
}

/*!
 * \brief Wyświetla wartości wczytanych parametrów
 */
void Interp4Set::PrintParams() const
{
  cout << "Pozycja: (" << _Pos_X << ", " << _Pos_Y << ", " << _Pos_Z << ")" << endl;
  cout << "Orientacja: OX=" << _Angle_OX_deg << "stopni, OY=" << _Angle_OY_deg 
       << "stopni, OZ=" << _Angle_OZ_deg << "stopni" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Set
 */
bool Interp4Set::ExecCmd( AbstractScene      &rScn, 
                          const char         *sMobObjName,
                          AbstractComChannel &rComChann )
{
  // TODO: Implementacja wykonania polecenia w kolejnych etapach
  cout << "Wykonywanie polecenia Set dla obiektu: " << sMobObjName << endl;
  PrintParams();
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Set ze strumienia
 * 
 * Polecenie Set wymaga parametrów:
 * - Współrzędna X [m]
 * - Współrzędna Y [m]
 * - Współrzędna Z [m]
 * - Kąt obrotu wokół osi OX [stopnie]
 * - Kąt obrotu wokół osi OY [stopnie]
 * - Kąt obrotu wokół osi OZ [stopnie]
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  double pos_x, pos_y, pos_z;
  double angle_ox, angle_oy, angle_oz;
  
  // Wczytaj współrzędną X
  Strm_CmdsList >> pos_x;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać współrzędnej X." << endl;
    return false;
  }
  
  // Wczytaj współrzędną Y
  Strm_CmdsList >> pos_y;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać współrzędnej Y." << endl;
    return false;
  }
  
  // Wczytaj współrzędną Z
  Strm_CmdsList >> pos_z;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać współrzędnej Z." << endl;
    return false;
  }
  
  // Wczytaj kąt OX
  Strm_CmdsList >> angle_ox;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać kąta OX." << endl;
    return false;
  }
  
  // Wczytaj kąt OY
  Strm_CmdsList >> angle_oy;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać kąta OY." << endl;
    return false;
  }
  
  // Wczytaj kąt OZ
  Strm_CmdsList >> angle_oz;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać kąta OZ." << endl;
    return false;
  }
  
  _Pos_X = pos_x;
  _Pos_Y = pos_y;
  _Pos_Z = pos_z;
  _Angle_OX_deg = angle_ox;
  _Angle_OY_deg = angle_oy;
  _Angle_OZ_deg = angle_oz;
  
  return true;
}

/*!
 * \brief Tworzy nową instancję polecenia Set
 */
AbstractInterp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}

/*!
 * \brief Wyświetla składnię polecenia
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  Nazwa_obiektu  Wsp_X[m]  Wsp_Y[m]  Wsp_Z[m]  Kat_OX[stopni]  Kat_OY[stopni]  Kat_OZ[stopni]" << endl;
}