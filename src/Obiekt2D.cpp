#include "Obiekt2D.hh"
#include <cmath>

Wektor2D Obiekt2D::WektorTranslacji;

/*!
 * \brief Metoda ustawiajaca macierz rotacji.
 *
 * Metoda ustawiajaca macierz rotacji.
 * param[in] - M - macierz ktorej elementy maja zostac ustawione.
 * param[in] - alfa - kat obrotu w stopniach.
 */
Macierz2x2 Obiekt2D::StworzMacierzRotacji(Macierz2x2 M, double alfa)
{
    alfa*=M_PI/180.0f;
    (M[0])[0] = cos(alfa);
    (M[0])[1] = -sin(alfa);
    (M[1])[0] = sin(alfa);
    (M[1])[1] = cos(alfa);
    return M;
}

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Obiekt2D.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Obiekt2D.
 * Pozwala wypisac na wyjscie wektory reprezentujace wspolrzedne.
 * param[in] - StrmWy - referencja do strumiena wyjsciowego.
 * param[in] - O - obiekt ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream& StrmWy, Obiekt2D O)
{
    unsigned int rozmiar, i;
    rozmiar=O.RozmiarObiektu();
    for(i=0; i<rozmiar; i++)
    {
        StrmWy << O[i];
    }
    return StrmWy;
}

