#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include "Interp4Move.hh"

using std::cerr;
using std::cout;
using std::endl;

extern "C"
{
  AbstractInterp4Command *CreateCmd(void);
  const char *GetCmdName() { return "Move"; }
}

/*!
 * \brief Tworzy instancję polecenia Move
 */
AbstractInterp4Command *CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}

/*!
 * \brief Konstruktor - inicjalizuje parametry zerami
 */
Interp4Move::Interp4Move() : _Speed_mS(0), _Distance_m(0)
{
}

/*!
 * \brief Wyświetla postać bieżącego polecenia
 */
void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " " << _Speed_mS << " m/s " << _Distance_m << " m" << endl;
}

/*!
 * \brief Wyświetla wartości wczytanych parametrów
 */
void Interp4Move::PrintParams() const
{
  cout << "  Prędkość: " << _Speed_mS << " m/s" << endl;
  cout << "  Odległość: " << _Distance_m << " m" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char *Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}

/*! \brief Wykonuje polecenie Move
 * \param[in,out] rScn - scena z obiektami mobilnymi
 * \param[in] sMobObjName - nazwa obiektu do przesunięcia
 * \param[in,out] rComChann - kanał komunikacyjny z serwerem graficznym
 * \return true jeśli operacja powiodła się
 */
bool Interp4Move::ExecCmd(AbstractScene &rScn,
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

  cout << "Move: " << sMobObjName << " speed=" << _Speed_mS
       << " m/s distance=" << _Distance_m << " m" << endl;

  // pblicz liczbę kroków
  const double STEP_TIME = 0.05;                // 50ms między krokami
  double total_time = _Distance_m / _Speed_mS; // czas całej trasy [s]
  int num_steps = (int)(total_time / STEP_TIME);
  if (num_steps < 1) // co najmniej jeden krok
    num_steps = 1;

  double step_distance = _Distance_m / num_steps; // droga na jeden krok

  // pętla animacji
  Vector3D current_pos = pObj->GetPositoin_m();

  for (int i = 0; i < num_steps; i++)
  {
    // zaktualizuj pozycję
    current_pos[0] += step_distance;
    pObj->SetPosition_m(current_pos);

    // wyślij UpdateObj do serwera
    std::ostringstream cmd;
    cmd << std::fixed << std::setprecision(2);
    cmd << "UpdateObj Name=" << sMobObjName;
    cmd << " Trans_m=(" << current_pos[0] << ","
        << current_pos[1] << "," << current_pos[2] << ")\n";

    int socket = rComChann.GetSocket();
    write(socket, cmd.str().c_str(), cmd.str().length());

    // czekaj przed następnym krokiem
    usleep((int)(STEP_TIME * 1000000));
  }

  cout << "  Move zakończony." << endl;
  return true;
}

/*!
 * \brief Wczytuje parametry polecenia Move ze strumienia
 *
 * Format: Move <Szybkosc_m/s> <DlugoscDrogi_m>
 *
 * \param[in] Strm_CmdsList - strumień z parametrami
 * \return true jeśli wczytano poprawnie
 */
bool Interp4Move::ReadParams(std::istream &Strm_CmdsList)
{
  double speed, distance;

  // Wczytaj prędkość
  Strm_CmdsList >> speed;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać prędkości." << endl;
    return false;
  }

  // Wczytaj długość drogi
  Strm_CmdsList >> distance;
  if (Strm_CmdsList.fail())
  {
    cerr << "!!! Błąd: Nie można wczytać długości drogi." << endl;
    return false;
  }

  // Walidacja: prędkość nie może być zerowa
  if (fabs(speed) < 0.001)
  {
    cerr << "!!! Błąd: Prędkość musi być różna od zera." << endl;
    return false;
  }

  // Walidacja: długość drogi musi być nieujemna
  if (distance < 0)
  {
    cerr << "!!! Błąd: Długość drogi musi być nieujemna." << endl;
    return false;
  }

  _Speed_mS = speed;
  _Distance_m = distance;

  return true;
}

/*!
 * \brief Tworzy nową instancję polecenia Move
 */
AbstractInterp4Command *Interp4Move::CreateCmd()
{
  return new Interp4Move();
}

/*!
 * \brief Wyświetla składnię polecenia
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  Nazwa_obiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}