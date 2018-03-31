#include "Wektor2D.hh"

/*!
 * \brief Przeciazenie operatora dodawania.
 *
 * Przeciazenie operatora dodawania.
 * Pozwala dodawac do siebie dwa wektory.
 */
Wektor2D Wektor2D::operator+(Wektor2D W)
{
    Wektor2D Wek;
    Wek[0]=Wsp[0]+W[0];
    Wek[1]=Wsp[1]+W[1];
    return Wek;
}

/*!
 * \brief Przeciazenie operatora odejmowania.
 *
 * Przeciazenie operatora odejmowania.
 * Pozwala odejmowac dwa wektory.
 */
Wektor2D Wektor2D::operator-(Wektor2D W)
{
    Wektor2D Wek;
    Wek[0]=Wsp[0]-W[0];
    Wek[1]=Wsp[1]-W[1];
    return Wek;
}

/*!
 * \brief Konstruktor z argumentami.
 *
 * Konstruktor z argumentami.
 * Pozwala stworzyc wektor z zadanych wspolrzednych.
 */
Wektor2D::Wektor2D(float x, float y)
{
    Wsp[0]=x;
    Wsp[1]=y;
}

/*!
 * \brief Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wektor2D
 *
 * Przeciazenie operatora czytania ze stumienia wejsciowego dla klasy Wektor2D.
 * Pozwala na bezposrednie pobieranie, ze stumienia wejsciowego, wspolrzednych wektora.
 * param[in] - Strm - referencja do strumiena wejsciowego.
 * param[in] - Wek - referencja do wektora ktorego wspolrzedne chcemy pobrac.
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &W)
{
    float x, y;
    
    Strm >> x;
    if(Strm.fail())
    {
        std::cerr << "Blad. Niepoprawna pierwsza wspolrzedna." << std::endl;
        Strm.setstate(std::ios_base::failbit);
        return Strm;
    } else W[0]=x;
    
    Strm >> y;
    if(Strm.fail())
    {
        std::cerr << "Blad. Niepoprawna druga wspolrzedna." << std::endl;
        Strm.setstate(std::ios_base::failbit);
        return Strm;
    } else W[1]=y;
    
    return Strm;
}

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Wektor2D.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Wektor2D.
 * Pozwala wypisac na wyjscie wartosci typu float wspolrzednych wektora.
 * param[in] - Strm - referencja do strumiena wyjsciowego.
 * param[in] - Wek - referencja do wektora ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, Wektor2D const& W)
{
    Strm << W[0] << " " << W[1] << std::endl;
    return Strm;
}
