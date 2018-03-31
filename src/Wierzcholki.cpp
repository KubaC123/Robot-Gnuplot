#include "Wierzcholki.hh"

/*!
 * \brief Metoda pozwalajaca na translacje wszystkich wspolrzednych.
 *
 * Metoda pozwalajaca na translacje wszystkich wspolrzednych.
 * Umozliwia dodanie do kazdego wierzcholka wektora translacji.
 * param[in] - wektor translacji.
 */
void Wierzcholki::Translacja(Wektor2D W)
{
    for (int i=0; i<RozmiarTablicyWierzcholkow(); i++) Wierz[i]=Wierz[i]+W;
}



/*!
 * \brief Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wierzcholki.
 *
 * Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wierzcholki.
 * Pozwala na bezposrednie pobieranie, ze stumienia wejsciowego, wartosci wierzcholkow.
 * param[in] - Strm - referencja do strumiena wejsciowego.
 * param[in] - Tab_Wierz - referencja do obiektu typu wierzcholki bedacego tablica wspolrzednych.
 */
std::istream& operator >> (std::istream &Strm, Wierzcholki &Tab_Wierz)
{
    int liczba_wierzcholkow;
    std::cout << "Podaj liczbe wierzcholkow tworzacych obiekt:" << std::endl;
    std::cin >> liczba_wierzcholkow;
    if(std::cin.fail())
    {
        std::cerr << "Blad. Nieprawidlowo podana liczba wierzcholkow." << std::endl;
        return Strm;
    }
    else
    {
        for(int i=0; i<liczba_wierzcholkow; i++)
        {
            Wektor2D W;
            std::cin >> W;
            if(!std::cin.fail()) Tab_Wierz.DodajWierzcholek(W);
        }
    }
    return Strm;
}


