#ifndef Przeszkoda_h
#define Przeszkoda_h
#include "Obiekt2D.hh"


/*!
 * \file Przeszkoda.hh
 *  Plik zawiera definicje klasy Przeszkoda,
 *  ktora reprezentuje przeszkody w dwuwymiarowym ukladzie wspolrzednych.
 */


/*!
 * \brief Klasa modeluje przeszkode.
 *
 * Klasa modeluje przeszkoda.
 * Klasa zawiera metody pozwalajace na tworzenie nowych przeszkod.
 */

class Przeszkoda: public Obiekt2D
{
    /* Dlugosci bokow przeszkody. */
    float wymX, wymY;
    /* Tablica pozwalajaca na przechowywanie wierzcholkow. */
    Wierzcholki Tab_Wierzcholkow;
public:
    /*!
     * \brief Przeciazenie operatora indeksowania.
     *
     * Przeciazenie operatora indeksowania.
     * param[in] - numer wierzcholka do jakiego chcemy sie dostac.
     */
    Wektor2D operator [] (int Ind) const { return Tab_Wierzcholkow[Ind]; }
    Wektor2D& operator [] (int Ind) { return Tab_Wierzcholkow[Ind]; }
    
    /*!
     * \brief Konstruktor.
     *
     * Konstruktor.
     */
    Przeszkoda() { }
    
    /*!
     * \brief Konstruktor z argumentami.
     *
     * Konstruktor z argumentami.
     * Tworzy przeszkode o zadanych wymiarach.
     * param[in] - W1 - pierwszy wierzcholek. podane boki rysowane sa od niego odpowiednio w prawo i w gore.
     * param[in] - WymX - pierwsza wspolrzedna wektora ruchu nowego robota.
     * param[in] - WymY - druga wspolrzedna wektora ruchu nowego robota.
     */
    Przeszkoda(Wektor2D W1, float WymX, float WymY);
    
    /*!
     * \brief Destruktor.
     *
     * Destruktor.
     */
    ~Przeszkoda() { }
};

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Przeszkoda.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Przeszkoda.
 * Pozwala wypisac na wyjscie wektory reprezentujace wspolrzedne wierzcholkow.
 * param[in] - StrmWy - referencja do strumiena wyjsciowego.
 * param[in] - P - referencja do robota ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, const Przeszkoda& P);

#endif
