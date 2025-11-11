#include <iostream>
#include "Interp4Rotate.hh"

using std::cout;
using std::endl;
using std::cerr;
using std::string;

extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}

/*!
 * \brief Tworzy instancję polecenia Rotate
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}

/*!
 * \brief Konstruktor
 */
Interp4Rotate::Interp4Rotate(): _AxisName(""), _AngularSpeed_degS(0), _Angle_deg(0)
{}

/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Rotate::PrintCmd() const
{
  cout << GetCmdName() << " " << _AxisName << " " 
       << _AngularSpeed_degS << "stopni/s " << _Angle_deg << "stopni" << endl;
}

/*!
 * \brief Wyświetla wartości wczytanych parametrów
 */
void Interp4Rotate::PrintParams() const
{
  cout << "Oś: " << _AxisName << ", Prędkość kątowa: " << _AngularSpeed_degS 
       << " stopni/s, Kąt: " << _Angle_deg << "stopni" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Rotate
 */
bool Interp4Rotate::ExecCmd( AbstractScene      &rScn, 
                             const char         *sMobObjName,
                             AbstractComChannel &rComChann )
{
  // TODO: Implementacja wykonania polecenia w kolejnych etapach
  cout << "Wykonywanie polecenia Rotate dla obiektu: " << sMobObjName << endl;
  PrintParams();
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Rotate ze strumienia
 * 
 * Polecenie Rotate wymaga parametrów:
 * - Nazwa osi (OX, OY lub OZ)
 * - Prędkość kątowa [°/s]
 * - Kąt obrotu [°]
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  string axis_name;
  double angular_speed, angle;
  
  // Wczytaj nazwę osi
  Strm_CmdsList >> axis_name;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać nazwy osi." << endl;
    return false;
  }
  
  // Walidacja nazwy osi
  if (axis_name != "OX" && axis_name != "OY" && axis_name != "OZ") {
    cerr << "!!! Błąd: Niepoprawna nazwa osi. Dozwolone: OX, OY, OZ." << endl;
    return false;
  }
  
  // Wczytaj prędkość kątową
  Strm_CmdsList >> angular_speed;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać prędkości kątowej." << endl;
    return false;
  }
  
  // Wczytaj kąt obrotu
  Strm_CmdsList >> angle;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać kąta obrotu." << endl;
    return false;
  }
  
  // Walidacja kąta (musi być nieujemny zgodnie z opisem zadania)
  if (angle < 0) {
    cerr << "!!! Błąd: Kąt obrotu musi być nieujemny." << endl;
    return false;
  }
  
  _AxisName = axis_name;
  _AngularSpeed_degS = angular_speed;
  _Angle_deg = angle;
  
  return true;
}

/*!
 * \brief Tworzy nową instancję polecenia Rotate
 */
AbstractInterp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}

/*!
 * \brief Wyświetla składnię polecenia
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  Nazwa_obiektu  Nazwa_Osi  Szybkosc_katowa[stopnie/s]  Kat_obrotu[stopni]]" << endl;
}