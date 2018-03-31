#include "Przeszkoda.hh"

/*!
 * \brief Konstruktor z argumentami.
 *
 * Konstruktor z argumentami.
 * Tworzy przeszkode o zadanych wymiarach.
 * param[in] - W1 - pierwszy wierzcholek. podane boki rysowane sa od niego odpowiednio w prawo i w gore.
 * param[in] - WymX - pierwsza wspolrzedna wektora ruchu nowego robota.
 * param[in] - WymY - druga wspolrzedna wektora ruchu nowego robota.
 */
Przeszkoda::Przeszkoda(Wektor2D W1, float WymX, float WymY)
{
    wymX=WymX;
    wymY=WymY;
    /* Wekotry W2, W3, W4 to kolejne wierzcholki przeszkody, ktore powstaja po dodaniu do wspolrzednych W1 wymiarow. */
    Wektor2D W2(W1[0], W1[1]+WymY), W3(W1[0]+WymX, W1[1]+WymY), W4(W1[0]+WymX, W1[1]);
    Tab_Wierzcholkow.DodajWierzcholek(W1);
    Tab_Wierzcholkow.DodajWierzcholek(W2);
    Tab_Wierzcholkow.DodajWierzcholek(W3);
    Tab_Wierzcholkow.DodajWierzcholek(W4);
}

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Przeszkoda.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Przeszkoda.
 * Pozwala wypisac na wyjscie wektory reprezentujace wspolrzedne wierzcholkow.
 * param[in] - StrmWy - referencja do strumiena wyjsciowego.
 * param[in] - P - referencja do robota ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, const Przeszkoda& P)
{
    return Strm << P[0] << "  " << P[1] << "  " << P[2] << "  " << P[3] << "  "
    << P[0] << std::endl;
}
