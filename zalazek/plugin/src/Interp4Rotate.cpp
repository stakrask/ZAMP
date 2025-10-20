#include <iostream>
#include "Interp4Rotate.hh"


using std::cout;
using std::endl;


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
 * \brief Konstruktor inicjalizujący
 */
Interp4Rotate::Interp4Rotate(): _Angle_rad(0)
{}


/*!
 * \brief Wyświetla postać polecenia z parametrami
 */
void Interp4Rotate::PrintCmd() const
{
  cout << GetCmdName() << " " << _Angle_rad << endl;
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
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
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
  cout << "   Rotate  NazwaObiektu  Kat[rad]" << endl;
}