#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH
#include <iostream>

/*!
 * \file Wektor2D.hh
 *  Plik zawiera definicje klasy Wektor2D,
 *  ktora modeluje wektor w dwuwymiarowym ukladzie wspolrzednych.
 */


/*!
 * \brief Klasa modelujaca wektor w dwuwymiarowym ukladzie wspolrzednych.
 *
 * Wspolrzedne wektora przechowywane sa w tablicy.
 * Klasa zawiera potrzebne do pobierania wartosci wspolrzednych i operacji na wektorach.
 */

class Wektor2D
{
    /* Tablica przechowujaca wspolrzedne x i y wektora. */
    float Wsp[2];
public:
    /*!
     * \brief Przeciazenie operatora indeksowania.
     *
     * Przeciazenie operatora indeksowania. Zwraca wspolrzedna wektora.
     * param[in] - numer indeksu do ktorego chcemy sie dostac.
     */
    float operator [] (int Indeks) const { return Wsp[Indeks]; }
    float& operator[] (int Indeks) { return Wsp[Indeks]; }
    
    /*!
     * \brief Przeciazenie operatora dodawania.
     *
     * Przeciazenie operatora dodawania.
     * Pozwala dodawac do siebie dwa wektory.
     */
    Wektor2D operator + (Wektor2D W);
    
    /*!
     * \brief Przeciazenie operatora odejmowania.
     *
     * Przeciazenie operatora odejmowania.
     * Pozwala odejmowac dwa wektory.
     */
    Wektor2D operator - (Wektor2D W);
    
    /*!
     * \brief Konstruktor bezargumentowy.
     *
     * Konstruktor bezargumentowy.
     * Domyslnie wspolrzedna maja wartosc x=0, y=0.
     */
    Wektor2D() { Wsp[0]=0; Wsp[1]=0; }
    
    /*!
     * \brief Konstruktor z argumentami.
     *
     * Konstruktor z argumentami.
     * Pozwala stworzyc wektor z zadanych wspolrzednych.
     */
    Wektor2D(float x, float y);
    
    /*!
     * \brief Destruktor.
     *
     * Destruktor.
     */
    ~Wektor2D() { }
};

/*!
 * \brief Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wektor2D
 *
 * Przeciazenie operatora czytania ze stumienia wejsciowego dla klasy Wektor2D.
 * Pozwala na bezposrednie pobieranie, ze stumienia wejsciowego, wspolrzednych wektora.
 * param[in] - Strm - referencja do strumiena wejsciowego.
 * param[in] - Wek - referencja do wektora ktorego wspolrzedne chcemy pobrac.
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Wektor2D.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Wektor2D.
 * Pozwala wypisac na wyjscie wartosci typu float wspolrzednych wektora.
 * param[in] - Strm - referencja do strumiena wyjsciowego.
 * param[in] - Wek - referencja do wektora ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, Wektor2D const& Wek);

#endif
