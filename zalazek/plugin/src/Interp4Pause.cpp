#include <iostream>
#include "Interp4Pause.hh"


using std::cout;
using std::endl;


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
 * \brief Konstruktor inicjalizujący
 */
Interp4Pause::Interp4Pause(): _Time_s(0)
{}


/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Pause::PrintCmd() const
{
  cout << GetCmdName() << " " << _Time_s << endl;
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
                            AbstractComChannel &rComChann
                          )
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 * \brief Wczytuje parametry polecenia ze strumienia
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
  cout << "   Pause  NazwaObiektu  Czas[s]" << endl;
}