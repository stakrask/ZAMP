#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"
#include <string>

/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawiera definicję klasy Interp4Rotate
 */

/*!
 * \brief Modeluje polecenie obracające obiekt 
 *
 * Klasa modeluje polecenie Rotate, które obraca obiekt
 * wokół zadanej osi z określoną prędkością kątową na określony kąt
 */
class Interp4Rotate: public AbstractInterp4Command {
  /*
   * Wartości parametrów polecenia
   */
  std::string _AxisName;           // Nazwa osi: OX, OY lub OZ
  double      _AngularSpeed_degS;  // Prędkość kątowa [stopnie/s]
  double      _Angle_deg;          // Kąt obrotu [stopnie]
  
 public:
  /*!
   * \brief Konstruktor
   */
  Interp4Rotate();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintCmd() const override;
  /*!
   * \brief Wyświetla składnię polecenia
   */
  virtual void PrintSyntax() const override;
  /*!
   * \brief Wyświetla wartości wczytanych parametrów
   */
  virtual void PrintParams() const override;

  /*!
   * \brief Wyświetla nazwę polecenia
   */
  virtual const char* GetCmdName() const override;

  /*!
   * \brief Wykonuje polecenie oraz wizualizuje jego realizację
   *
   * Wykonuje polecenie oraz wizualizuje jego realizację.
   * \param[in,out]  rScn - scena zawierającą obiekty mobilne,
   * \param[in]      sMobObjName - wskaźnik na nazwę lokalizującą i identyfikującą obiekt,
   * \param[in,out]  rComChann - kanał komunikacyjny z serwerem graficznym.
   * \retval true - operacja powiodła się,
   * \retval false - w przypadku przeciwnym.
   */
  virtual bool ExecCmd( AbstractScene      &rScn, 
                        const char         *sMobObjName,
                        AbstractComChannel &rComChann ) override;
  /*!
   * \brief Czyta wartości parametrów danego polecenia
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList) override;
 
  /*!
   * \brief Tworzy instancję polecenia
   *
   * Ta metoda nie musi być zdefiniowana w klasie bazowej.
   */
  static AbstractInterp4Command* CreateCmd();
 };

#endif