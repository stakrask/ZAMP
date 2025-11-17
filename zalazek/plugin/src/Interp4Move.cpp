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
Interp4Move::Interp4Move() : _Speed_mmS(0), _Distance_m(0)
{
}

/*!
 * \brief Wyświetla postać bieżącego polecenia
 */
void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " " << _Speed_mmS << " m/s " << _Distance_m << " m" << endl;
}

/*!
 * \brief Wyświetla wartości wczytanych parametrów
 */
void Interp4Move::PrintParams() const
{
  cout << "  Prędkość: " << _Speed_mmS << " m/s" << endl;
  cout << "  Odległość: " << _Distance_m << " m" << endl;
}

/*!
 * \brief Zwraca nazwę polecenia
 */
const char *Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}

/*!
 * \brief Wykonuje polecenie Move z animacją
 *
 * ALGORYTM:
 * 1. Znajdź obiekt na scenie
 * 2. Oblicz parametry animacji (liczba kroków, delta na krok)
 * 3. Oblicz kierunek ruchu (wzdłuż lokalnej osi OX obiektu)
 * 4. W pętli:
 *    - Zaktualizuj pozycję obiektu
 *    - Wyślij UpdateObj do serwera
 *    - Odczekaj czas kroku
 *
 * \param[in,out] rScn - scena zawierająca obiekty mobilne
 * \param[in] sMobObjName - nazwa obiektu do przesunięcia
 * \param[in,out] rComChann - kanał komunikacyjny z serwerem
 * \return true jeśli sukces, false w przypadku błędu
 */
bool Interp4Move::ExecCmd(AbstractScene &rScn,
                          const char *sMobObjName,
                          AbstractComChannel &rComChann)
{
  
  AbstractMobileObj *pObj = rScn.FindMobileObj(sMobObjName);

  if (!pObj)
  {
    cerr << "!!! Błąd: Nie znaleziono obiektu '" << sMobObjName << "'" << endl;
    return false;
  }

  cout << "\n=== Wykonywanie Move dla: " << sMobObjName << " ===" << endl;
  cout << "Prędkość: " << _Speed_mmS << " m/s, Odległość: " << _Distance_m << " m" << endl;

  const double FRAME_TIME = 0.04; // 40ms = 25 FPS

  // Oblicz całkowity czas trwania ruchu
  double totalTime_s = fabs(_Distance_m / _Speed_mmS);

  // Oblicz liczbę kroków (klatek animacji)
  int numSteps = (int)(totalTime_s / FRAME_TIME);
  if (numSteps < 1)
    numSteps = 1; // Przynajmniej 1 krok

  // Oblicz przesunięcie na jeden krok
  double stepDistance = _Distance_m / numSteps;

  cout << "Animacja: " << numSteps << " kroków, "
       << (FRAME_TIME * 1000) << " ms na krok" << endl;

  double yawAngle_rad = pObj->GetAng_Yaw_deg() * M_PI / 180.0;

  // Wektor kierunku: lokalny OX po obrocie o Yaw
  Vector3D direction;
  direction[0] = cos(yawAngle_rad); // składowa X
  direction[1] = sin(yawAngle_rad); // składowa Y
  direction[2] = 0;                 // składowa Z (ruch w płaszczyźnie XY)

  // Wektor przesunięcia na jeden krok
  Vector3D stepVector = direction * stepDistance;
  Vector3D startPos = pObj->GetPositoin_m();
  cout << "Pozycja początkowa: " << startPos << endl;

  for (int i = 0; i < numSteps; ++i)
  {
    // Zaktualizuj pozycję obiektu
    Vector3D currentPos = pObj->GetPositoin_m();
    Vector3D newPos = currentPos + stepVector;
    pObj->SetPosition_m(newPos);

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3);

    oss << "UpdateObj Name=" << sMobObjName;
    oss << " RotXYZ_deg=(" << pObj->GetAng_Roll_deg() << ","
        << pObj->GetAng_Pitch_deg() << "," << pObj->GetAng_Yaw_deg() << ")";
    oss << " Trans_m=(" << newPos[0] << "," << newPos[1] << "," << newPos[2] << ")";
    oss << "\n";

    std::string updateCmd = oss.str();

    // Wyślij polecenie do serwera (thread-safe)
    rComChann.LockAccess();
    int socket = rComChann.GetSocket();

    ssize_t totalSent = 0;
    ssize_t toSend = updateCmd.length();
    const char *pMessage = updateCmd.c_str();

    while (toSend > 0)
    {
      ssize_t sent = write(socket, pMessage, toSend);
      if (sent < 0)
      {
        cerr << "!!! Błąd wysyłania UpdateObj" << endl;
        rComChann.UnlockAccess();
        return false;
      }
      totalSent += sent;
      toSend -= sent;
      pMessage += sent;
    }

    rComChann.UnlockAccess();

    // Postęp (co 10 kroków)
    if ((i + 1) % 10 == 0 || i == numSteps - 1)
    {
      double progress = ((double)(i + 1) / numSteps) * 100.0;
      cout << "  Postęp: " << (int)progress << "% (krok "
           << (i + 1) << "/" << numSteps << ")" << endl;
    }

    // Odczekaj czas klatki (40ms = 40000 mikrosekund)
    usleep((int)(FRAME_TIME * 1000000));
  }

  Vector3D finalPos = pObj->GetPositoin_m();
  cout << "Pozycja końcowa: " << finalPos << endl;

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

  _Speed_mmS = speed;
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