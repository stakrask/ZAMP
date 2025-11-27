#include <iostream>
#include <unistd.h>
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
Interp4Pause::Interp4Pause(): _Time_ms(0)
{}

/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Pause::PrintCmd() const
{
  cout << GetCmdName() << " " << _Time_ms << " ms" << endl;
}

/*!
 * \brief Wyświetla wartości wczytanych parametrów
 */
void Interp4Pause::PrintParams() const
{
  cout << "Czas pauzy: " << _Time_ms << " ms (" << (_Time_ms / 1000.0) << " s)" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char* Interp4Pause::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Pause - wstrzymuje wykonanie na zadany czas
 * 
 * \param[in,out] rScn - scena z obiektami mobilnymi (nieużywana)
 * \param[in] sMobObjName - nazwa obiektu (nieużywana dla Pause)
 * \param[in,out] rComChann - kanał komunikacyjny (nieużywany)
 * \return true - operacja zawsze się powodzi
 */
bool Interp4Pause::ExecCmd( AbstractScene      &rScn, 
  const char         *sMobObjName,
  AbstractComChannel &rComChann )
{
cout << "Pause: " << _Time_ms << " ms (" << (_Time_ms / 1000.0) << " s)" << endl;

// Konwersja milisekund na mikrosekundy (usleep przyjmuje mikrosekundy)
// 1 ms = 1000 µs
useconds_t microseconds = (useconds_t)(_Time_ms * 1000);

// Wstrzymanie wykonania
usleep(microseconds);

cout << "  Pause zakończony." << endl;
return true;
}

/*!
 * \brief Wczytuje parametry polecenia Pause ze strumienia
 * 
 * Polecenie Pause wymaga parametru:
 * - Czas wstrzymania [ms]
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  double time;
  
  // Wczytaj czas w milisekundach
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
  
  _Time_ms = time;
  
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
  cout << "   Pause  Czas_pauzy[ms]" << endl;
}