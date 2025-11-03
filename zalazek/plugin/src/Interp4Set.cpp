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
Interp4Set::Interp4Set(): _Pos_X(0), _Pos_Y(0)
{}

/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Set::PrintCmd() const
{
  cout << GetCmdName() << " X=" << _Pos_X << " Y=" << _Pos_Y << endl;
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
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Set ze strumienia
 * 
 * Polecenie Set wymaga parametrów:
 * - Współrzędna X [m]
 * - Współrzędna Y [m]
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  double pos_x, pos_y;
  
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
  
  _Pos_X = pos_x;
  _Pos_Y = pos_y;
  
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
  cout << "   Set  Wsp_X[m]  Wsp_Y[m]" << endl;
}