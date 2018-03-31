#include "Macierz2x2.hh"

/*!
 * \brief Konstruktor z argumentami.
 *
 * Konstruktor z argumentami.
 * Pozwala stworzyc macierz z zadanych elementow.
 * Zapis e11 oznacza wiersz 1, element 1. Odpowiednio pozostale
 */
Macierz2x2::Macierz2x2(float e11, float e12, float e21, float e22)
{
    Wiersz[0] = Wektor2D(e11, e12);
    Wiersz[1] = Wektor2D(e21, e22);
}

/*!
 * \brief Przeciazenie operatora mnozenia macierzy przez wektor.
 *
 * Przeciazenie operatora mnozenia macierzy przez wektor.
 * Pozwala zgodnie z prawami algebry przemnozyc elementy macierzy przez elementy wektora.
 */
Wektor2D Macierz2x2::operator*(Wektor2D W)
{
    Wektor2D Wek;
    Wek[0]=W[0]*Wiersz[0][0]+W[1]*Wiersz[0][1];
    Wek[1]=W[0]*Wiersz[1][0]+W[1]*Wiersz[1][1];
    return Wek;
}

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Macierz2x2.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Macierz2x2.
 * Pozwala wypisac na wyjscie wspolrzedne obiektow typu Wektor2D reprezentujacych,
 * wiersze macierzy.
 * param[in] - Strm - referencja do strumiena wyjsciowego.
 * param[in] - M - referencja do macierzy ktorej elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, Macierz2x2 const& M)
{
    Strm << M[0] << std::endl << M[1];
    return Strm;
}
