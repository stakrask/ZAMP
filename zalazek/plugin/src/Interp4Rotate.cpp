#include <iostream>
#include "Interp4Rotate.hh"

using std::cout;
using std::endl;
using std::cerr;

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
Interp4Rotate::Interp4Rotate(): _Angle_rad(0)
{}

/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Rotate::PrintCmd() const
{
  cout << GetCmdName() << " " << _Angle_rad << " rad" << endl;
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
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Rotate ze strumienia
 * 
 * Polecenie Rotate wymaga parametru:
 * - Kąt obrotu [rad]
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  double angle;
  
  // Wczytaj kąt
  Strm_CmdsList >> angle;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać kąta obrotu." << endl;
    return false;
  }
  
  _Angle_rad = angle;
  
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
  cout << "   Rotate  Kat[rad]" << endl;
}