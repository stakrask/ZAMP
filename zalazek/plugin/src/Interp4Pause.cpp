#include <iostream>
#include "Interp4Pause.hh"

using std::cout;
using std::endl;
using std::cerr;

extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Pause"; }
}

/*!
 * \brief Tworzy instancję polecenia Pause
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Pause::CreateCmd();
}

/*!
 * \brief Konstruktor
 */
Interp4Pause::Interp4Pause(): _Time_s(0)
{}

/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Pause::PrintCmd() const
{
  cout << GetCmdName() << " " << _Time_s << " s" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char* Interp4Pause::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Pause
 */
bool Interp4Pause::ExecCmd( AbstractScene      &rScn, 
                            const char         *sMobObjName,
                            AbstractComChannel &rComChann )
{
  // TODO: Implementacja wykonania polecenia w kolejnych etapach
  cout << "Wykonywanie polecenia Pause dla obiektu: " << sMobObjName << endl;
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Pause ze strumienia
 * 
 * Polecenie Pause wymaga parametru:
 * - Czas wstrzymania [s]
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  double time;
  
  // Wczytaj czas
  Strm_CmdsList >> time;
  if (Strm_CmdsList.fail()) {
    cerr << "!!! Błąd: Nie można wczytać czasu wstrzymania." << endl;
    return false;
  }
  
  // Walidacja wartości
  if (time < 0) {
    cerr << "!!! Błąd: Czas musi być nieujemny." << endl;
    return false;
  }
  
  _Time_s = time;
  
  return true;
}

/*!
 * \brief Tworzy nową instancję polecenia Pause
 */
AbstractInterp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}

/*!
 * \brief Wyświetla składnię polecenia
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause  Czas[s]" << endl;
}