#ifndef WIERZCHOLKI_HH
#define WIERZCHOLKI_HH
#include "Macierz2x2.hh"
#include <vector>


/*!
 * \file Wierzcholki.hh
 *  Plik zawiera definicje klasy Wierzcholki,
 *  ktora pozwala na przechowywanie i dostep do wspolrzednych wierzcholkow obiektow 2D.
 */


/*!
 * \brief Klasa ulatwia przechowywanie wierzcholkow obiektow 2D.
 *
 * Klasa ulatwia przechowywanie wierzcholkow obiektow 2D.
 * Klasa zawiera metody pozwalajace na tworzenie i operowanie na wierzcholkach.
 */

class Wierzcholki
{
    /* Kontener vector przechowujacy wierzcholki obiektow w postaci wektorow. */
    std::vector<Wektor2D> Wierz;
public:
  void wyczysc(){Wierz.clear();}
    /*!
     * \brief Przeciazenie operatora indeksowania.
     *
     * Przeciazenie operatora indeksowania. Zwraca wierzcholek.
     * param[in] - numer elementu do ktorego chcemy sie dostac.
     */
    Wektor2D operator[] (int Indeks) const { return Wierz[Indeks]; }
    Wektor2D& operator[] (int Indeks) { return Wierz[Indeks]; }
    
    /*!
     * \brief Metoda zwracajaca rozmiar tablicy wierzcholkow.
     *
     * Metoda zwracajaca rozmiar tablicy wierzcholkow.
     */
    int RozmiarTablicyWierzcholkow() const { return (int)Wierz.size(); }
    
    /*!
     * \brief Metoda pozwalajaca na dodawanie kolejnych wierzcholkow.
     *
     * Metoda pozwalajaca na dodawanie kolejnych wierzcholkow.
     * param[in] - wektor reprezentujacy wspolrzedne wierzcholka.
     */
    void DodajWierzcholek(Wektor2D W) { Wierz.push_back(W); }
    
    /*!
     * \brief Metoda pozwalajaca na translacje wszystkich wspolrzednych.
     *
     * Metoda pozwalajaca na translacje wszystkich wspolrzednych.
     * Umozliwia dodanie do kazdego wierzcholka wektora translacji.
     * param[in] - wektor translacji.
     */
    void Translacja(Wektor2D W);
    
    /*!
     * \brief Konstuktor 
     *
     * Konstruktor.
     */
    Wierzcholki() { }
    
    /*!
     * \brief Destruktor
     *
     * Destruktor. Usuwa wszystkie wierzcholki.
     */
    ~Wierzcholki() { Wierz.clear(); }
};

/*!
 * \brief Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wierzcholki.
 *
 * Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wierzcholki.
 * Pozwala na bezposrednie pobieranie, ze stumienia wejsciowego, wartosci wierzcholkow.
 * param[in] - Strm - referencja do strumiena wejsciowego.
 * param[in] - Tab_Wierz - referencja do obiektu typu wierzcholki bedacego tablica wspolrzednych.
 */
std::istream& operator >> (std::istream &Strm, Wierzcholki &Tab_Wierz);



#endif
