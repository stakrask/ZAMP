#include <iostream>
#include "Interp4Move.hh"

using std::cout;
using std::endl;
using std::cerr;

extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}

/*!
 * \brief Tworzy instancję polecenia Move
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}

/*!
 * \brief Konstruktor
 */
Interp4Move::Interp4Move(): _Speed_mmS(0), _Distance_m(0)
{}

/*!
 * \brief Wyświetla postać bieżącego polecenia
 */
void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " " << _Speed_mmS << " " << _Distance_m << endl;
}

/*!
 * \brief Wyświetla wartości wczytanych parametrów
 */
void Interp4Move::PrintParams() const
{
  cout << "Prędkość: " << _Speed_mmS << " m/s, Odległość: " << _Distance_m << " m" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Move
 */
bool Interp4Move::ExecCmd( AbstractScene      &rScn, 
                           const char         *sMobObjName,
                           AbstractComChannel &rComChann )
{
  // TODO: Implementacja wykonania polecenia w kolejnych etapach
  cout << "Wykonywanie polecenia Move dla obiektu: " << sMobObjName << endl;
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Move ze strumienia
 * 
 * Polecenie Move wymaga parametrów:
 * - Szybkość [m/s]
 * - Długość drogi [m]
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  double speed, distance;
  
  // Wczytaj prędkość
  Strm_CmdsList >> speed;
  if (Strm_CmdsList.fail()) {
    cerr << "Błąd odczytu prędkości." << endl;
    return false;
  }
  
  // Wczytaj długość drogi
  Strm_CmdsList >> distance;
  if (Strm_CmdsList.fail()) {
    cerr << "Błąd odczytu długości drogi." << endl;
    return false;
  }
  
  _Speed_mmS = speed;
  _Distance_m = distance;
  
  return true;
}

/*!
 * \brief Tworzy nową instancję polecenia Move
 */
AbstractInterp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}

/*!
 * \brief Wyświetla składnię polecenia
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}