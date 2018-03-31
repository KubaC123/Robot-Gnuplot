#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#include "Wektor2D.hh"


/*!
 * \file Macierz2x2.hh
 *  Plik zawiera definicje klasy Macierz2x2,
 *  ktora modeluje macierz.
 */


/*!
 * \brief Klasa modelujaca macierz czteroelemenetowa.
 *
 * Klasa modelujaca macierz czteroelemenetowa.
 * Elementy macierzy reprezentowane sa przez dwa obiekty typu Wektor2D.
 * Klasa zawiera potrzebne przeciazenia do pobierania wierszy i operacji na macierzy.
 */

class Macierz2x2
{
    /* Tablica dwoch wektorow reprezentujacych wiersze macierzy. */
    Wektor2D Wiersz[2];
public:
    /*!
     * \brief Przeciazenie operatora indeksowania.
     *
     * Przeciazenie operatora indeksowania. Zwraca wiersz.
     * param[in] - numer wiersza do ktorego chcemy sie dostac.
     */
    const Wektor2D& operator[] (int Wie) const { return Wiersz[Wie]; }
    Wektor2D& operator[] (int Wie) { return Wiersz[Wie]; }
    
    /*!
     * \brief Konstruktor bezargumentowy.
     *
     * Konstruktor bezargumentowy.
     * Domyslnie elementy maja wartosc 0.
     */
    Macierz2x2() { Wiersz[0]=Wektor2D(), Wiersz[1]=Wektor2D(); }
    
    /*!
     * \brief Konstruktor z argumentami.
     *
     * Konstruktor z argumentami.
     * Pozwala stworzyc macierz z zadanych elementow.
     * Zapis e11 oznacza wiersz 1, element 1. Odpowiednio pozostale
     */
    Macierz2x2(float e11, float e12, float e21, float e22);
    
    /*!
     * \brief Destruktor.
     *
     * Destruktor.
     */
    ~Macierz2x2() { }
    
    /*!
     * \brief Przeciazenie operatora mnozenia macierzy przez wektor.
     *
     * Przeciazenie operatora mnozenia macierzy przez wektor.
     * Pozwala zgodnie z prawami algebry przemnozyc elementy macierzy przez elementy wektora.
     */
    Wektor2D operator * (Wektor2D W);
};

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Macierz2x2.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Macierz2x2.
 * Pozwala wypisac na wyjscie wspolrzedne obiektow typu Wektor2D reprezentujacych,
 * wiersze macierzy.
 * param[in] - Strm - referencja do strumiena wyjsciowego.
 * param[in] - M - referencja do macierzy ktorej elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, Macierz2x2 const& M);

#endif
