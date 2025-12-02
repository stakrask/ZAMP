#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include "Interp4Rotate.hh"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

extern "C"
{
  AbstractInterp4Command *CreateCmd(void);
  const char *GetCmdName() { return "Rotate"; }
}

/*!
 * \brief Tworzy instancję polecenia Rotate
 */
AbstractInterp4Command *CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}

/*!
 * \brief Konstruktor
 */
Interp4Rotate::Interp4Rotate() : _AxisName(""), _AngularSpeed_degS(0), _Angle_deg(0)
{
}

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
const char *Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Rotate - animowany obrót obiektu wokół zadanej osi
 *
 * \param[in,out] rScn - scena z obiektami mobilnymi
 * \param[in] sMobObjName - nazwa obiektu do obrócenia
 * \param[in,out] rComChann - kanał komunikacyjny z serwerem graficznym
 * \return true jeśli operacja powiodła się
 */
bool Interp4Rotate::ExecCmd(AbstractScene &rScn,
                            const char *sMobObjName,
                            AbstractComChannel &rComChann)
{
  AbstractMobileObj *pObj = rScn.FindMobileObj(sMobObjName);
  if (!pObj)
  {
    cerr << "!!! Błąd: Nie znaleziono obiektu '" << sMobObjName << "'" << endl;
    return false;
  }

  const double STEP_TIME = 0.05; // 50ms między krokami (20 FPS)

  // Oblicz całkowity czas obrotu
  double total_time = fabs(_Angle_deg / _AngularSpeed_degS); // [s]

  // Oblicz liczbę kroków
  int num_steps = (int)(total_time / STEP_TIME);
  if (num_steps < 1) // Co najmniej jeden krok
    num_steps = 1;

  // Oblicz przyrost kąta na jeden krok
  double step_angle = _Angle_deg / num_steps; // [deg]

  cout << "  Czas całkowity: " << total_time << " s" << endl;
  cout << "  Liczba kroków: " << num_steps << endl;
  cout << "  Kąt na krok: " << step_angle << " deg" << endl;

  // Kierunek zależy od znaku prędkości kątowej:
  // - dodatnia prędkość -> obrót zgodny z kierunkiem osi
  // - ujemna prędkość -> obrót przeciwny
  int direction = (_AngularSpeed_degS >= 0) ? 1 : -1;
  double angle_increment = step_angle * direction;

  for (int i = 0; i < num_steps; i++)
  {
    // 4a) Pobierz aktualny kąt w zależności od osi
    double current_angle = 0.0;

    if (_AxisName == "OX")
    {
      current_angle = pObj->GetAng_Roll_deg();
    }
    else if (_AxisName == "OY")
    {
      current_angle = pObj->GetAng_Pitch_deg();
    }
    else if (_AxisName == "OZ")
    {
      current_angle = pObj->GetAng_Yaw_deg();
    }
    else
    {
      cerr << "!!! Błąd: Nierozpoznana oś '" << _AxisName << "'" << endl;
      return false;
    }

    // 4b) Oblicz nowy kąt
    double new_angle = current_angle + angle_increment;

    // 4c) Ustaw nowy kąt
    if (_AxisName == "OX")
    {
      pObj->SetAng_Roll_deg(new_angle);
    }
    else if (_AxisName == "OY")
    {
      pObj->SetAng_Pitch_deg(new_angle);
    }
    else if (_AxisName == "OZ")
    {
      pObj->SetAng_Yaw_deg(new_angle);
    }

    // Pobierz wszystkie parametry obiektu
    Vector3D position = pObj->GetPositoin_m();
    double roll = pObj->GetAng_Roll_deg();
    double pitch = pObj->GetAng_Pitch_deg();
    double yaw = pObj->GetAng_Yaw_deg();

    // Zbuduj polecenie UpdateObj
    std::ostringstream cmd;
    cmd << std::fixed << std::setprecision(2);
    cmd << "UpdateObj Name=" << sMobObjName;
    cmd << " RotXYZ_deg=(" << roll << "," << pitch << "," << yaw << ")";
    cmd << " Trans_m=(" << position[0] << "," << position[1] << "," << position[2] << ")";
    cmd << "\n";

    // Wyślij polecenie do serwera
    if (rComChann.Send(cmd.str().c_str()) < 0)
    {
      cerr << "!!! Błąd wysyłania polecenia UpdateObj" << endl;
      return false;
    }

    // Debug: pokaż co wysyłamy (opcjonalnie)
    if (i % 5 == 0 || i == num_steps - 1)
    { // Co 5 kroków lub ostatni
      cout << "  Krok " << (i + 1) << "/" << num_steps
           << ": kąt " << _AxisName << " = " << new_angle << " deg" << endl;
    }

    // 4f) Czekaj przed następnym krokiem
    usleep((int)(STEP_TIME * 1000000)); // Zamień sekundy na mikrosekundy
  }

  cout << "  Rotate zakończony." << endl;
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
bool Interp4Rotate::ReadParams(std::istream &Strm_CmdsList)
{
  string axis_name;
  double angular_speed, angle;

  // Wczytaj nazwę osi
  Strm_CmdsList >> axis_name;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać nazwy osi." << endl;
    return false;
  }

  // Walidacja nazwy osi
  if (axis_name != "OX" && axis_name != "OY" && axis_name != "OZ")
  {
    cerr << "!!! Błąd: Niepoprawna nazwa osi. Dozwolone: OX, OY, OZ." << endl;
    return false;
  }

  // Wczytaj prędkość kątową
  Strm_CmdsList >> angular_speed;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać prędkości kątowej." << endl;
    return false;
  }

  // Wczytaj kąt obrotu
  Strm_CmdsList >> angle;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać kąta obrotu." << endl;
    return false;
  }

  // Walidacja kąta (musi być nieujemny zgodnie z opisem zadania)
  if (angle < 0)
  {
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
AbstractInterp4Command *Interp4Rotate::CreateCmd()
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