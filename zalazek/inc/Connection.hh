#ifndef CONNECTION_HH
#define CONNECTION_HH

/*!
 * \file
 * \brief Funkcje do komunikacji z serwerem graficznym
 *
 * Zawiera proste funkcje do nawiązywania połączenia
 * i wysyłania poleceń do serwera graficznego.
 */

/*!
 * \brief Otwiera połączenie z serwerem graficznym
 * 
 * Funkcja nawiązuje połączenie TCP z serwerem graficznym
 * działającym na localhost:6217
 * 
 * \param[out] rSocket - referencja do zmiennej, w której zostanie zapisany deskryptor gniazda
 * \return true jeśli połączenie się powiodło, false w przeciwnym wypadku
 */
bool OpenConnection(int& rSocket);

/*!
 * \brief Wysyła wiadomość do serwera
 * 
 * Wysyła wiadomość tekstową przez gniazdo sieciowe.
 * Funkcja automatycznie obsługuje częściowe wysyłanie danych.
 * 
 * \param[in] Socket - deskryptor gniazda sieciowego
 * \param[in] sMessage - wiadomość do wysłania (powinna kończyć się '\n')
 * \return 0 jeśli wysłanie się powiodło, wartość ujemna w przypadku błędu
 */
int Send(int Socket, const char* sMessage);

/*!
 * \brief Zamyka połączenie z serwerem
 * 
 * Wysyła polecenie Close i zamyka gniazdo sieciowe.
 * 
 * \param[in] Socket - deskryptor gniazda do zamknięcia
 */
void CloseConnection(int Socket);

#endif