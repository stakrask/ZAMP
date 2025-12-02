#include <iostream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include "Interp4Set.hh"

using std::cerr;
using std::cout;
using std::endl;

extern "C"
{
  AbstractInterp4Command *CreateCmd(void);
  const char *GetCmdName() { return "Set"; }
}

/*!
 * \brief Tworzy instancję polecenia Set
 */
AbstractInterp4Command *CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}

/*!
 * \brief Konstruktor
 */
Interp4Set::Interp4Set() : _Pos_X(0), _Pos_Y(0), _Pos_Z(0),
                           _Angle_OX_deg(0), _Angle_OY_deg(0), _Angle_OZ_deg(0)
{
}

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
const char *Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Set - ustawia pozycję i orientację obiektu
 *
 * \param[in,out] rScn - scena z obiektami mobilnymi
 * \param[in] sMobObjName - nazwa obiektu do ustawienia
 * \param[in,out] rComChann - kanał komunikacyjny z serwerem graficznym
 * \return true jeśli operacja powiodła się
 */
bool Interp4Set::ExecCmd(AbstractScene &rScn,
                         const char *sMobObjName,
                         AbstractComChannel &rComChann)
{
  // Znajdź obiekt na scenie
  AbstractMobileObj *pObj = rScn.FindMobileObj(sMobObjName);

  if (!pObj)
  {
    cerr << "!!! Błąd: Nie znaleziono obiektu '" << sMobObjName << "'" << endl;
    return false;
  }

  cout << "Set: " << sMobObjName
       << " pos=(" << _Pos_X << "," << _Pos_Y << "," << _Pos_Z << ") m, "
       << "rot=(" << _Angle_OX_deg << "," << _Angle_OY_deg << "," << _Angle_OZ_deg << ")°"
       << endl;

  // Przygotuj nową pozycję
  Vector3D new_position;
  new_position[0] = _Pos_X;
  new_position[1] = _Pos_Y;
  new_position[2] = _Pos_Z;

  // Ustaw nową pozycję
  pObj->SetPosition_m(new_position);

  // Ustaw nową orientację (kąty Roll-Pitch-Yaw)
  pObj->SetAng_Roll_deg(_Angle_OX_deg);  // Obrót wokół OX
  pObj->SetAng_Pitch_deg(_Angle_OY_deg); // Obrót wokół OY
  pObj->SetAng_Yaw_deg(_Angle_OZ_deg);   // Obrót wokół OZ

  // Przygotuj polecenie UpdateObj dla serwera graficznego
  std::ostringstream cmd;
  cmd << std::fixed << std::setprecision(2);
  cmd << "UpdateObj Name=" << sMobObjName;
  cmd << " RotXYZ_deg=(" << _Angle_OX_deg << ","
      << _Angle_OY_deg << "," << _Angle_OZ_deg << ")";
  cmd << " Trans_m=(" << _Pos_X << "," << _Pos_Y << "," << _Pos_Z << ")";
  cmd << "\n";

  // Wyślij polecenie do serwera
  if (rComChann.Send(cmd.str().c_str()) < 0)
  {
    cerr << "!!! Błąd wysyłania polecenia UpdateObj" << endl;
    return false;
  }

  cout << "  Set zakończony." << endl;
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
bool Interp4Set::ReadParams(std::istream &Strm_CmdsList)
{
  double pos_x, pos_y, pos_z;
  double angle_ox, angle_oy, angle_oz;

  // Wczytaj współrzędną X
  Strm_CmdsList >> pos_x;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać współrzędnej X." << endl;
    return false;
  }

  // Wczytaj współrzędną Y
  Strm_CmdsList >> pos_y;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać współrzędnej Y." << endl;
    return false;
  }

  // Wczytaj współrzędną Z
  Strm_CmdsList >> pos_z;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać współrzędnej Z." << endl;
    return false;
  }

  // Wczytaj kąt OX
  Strm_CmdsList >> angle_ox;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać kąta OX." << endl;
    return false;
  }

  // Wczytaj kąt OY
  Strm_CmdsList >> angle_oy;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać kąta OY." << endl;
    return false;
  }

  // Wczytaj kąt OZ
  Strm_CmdsList >> angle_oz;
  if (Strm_CmdsList.fail())
  {
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
AbstractInterp4Command *Interp4Set::CreateCmd()
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