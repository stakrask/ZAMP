#include <iostream>
#include "Interp4Set.hh"


using std::cout;
using std::endl;


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
 * \brief Konstruktor inicjalizujący
 */
Interp4Set::Interp4Set(): _Pos_X(0), _Pos_Y(0)
{}


/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Set::PrintCmd() const
{
  cout << GetCmdName() << " " << _Pos_X << " " << _Pos_Y << endl;
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
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
  cout << "   Set  NazwaObiektu  Wsp_X[m]  Wsp_Y[m]" << endl;
}