#ifndef SCIEZKA_HH
#define SCIEZKA_HH
#include "Obiekt2D.hh"

/*!
 * \file Sciezka.hh
 *  Plik zawiera definicje klasy Sciezka,
 *  ktora modeluje sciezke jako obiekt w dwuwymiarowym ukladzie wspolrzednych.
 */


/*!
 * \brief Klasa modeluje sciezke.
 *
 * Klasa modeluje sciezke jako obiekt w dwuwymiarowym ukladzie wspolrzednych.
 * Dziedziczy z klasy Obiekt2D.
 * Sciezka jest sladem ruchu robota, a jej kolejne punkty tworza wspolrzedne jego srodka.
 */

class Sciezka: public Obiekt2D
{
    /* Tablica wspolrzednych tworzacych sciezke. */
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
     * \brief Metoda pozwalajaca na dodawanie nowych wspolrzednych sciezki.
     *
     * Metoda pozwalajaca na dodawanie nowych wspolrzednych sciezki.
     * param[in] - wektor reprezentujacy nowa wspolrzedna. W programie bedzie to srodek robota po ruchu.
     */
    void DodajWierzcholekDoSciezki(Wektor2D W) { Tab_Wierzcholkow.DodajWierzcholek(W); }
    
    /*!
     * \brief Metoda pozwalajaca zidentyfikowac sciezke.
     *
     * Metoda pozwalajaca zidentyfikowac sciezke.
     */
    const char* NazwaObiektu() const { return "Sciezka"; }
    
    /*!
     * \brief Konstruktor.
     *
     * Konstruktor.
     */
    Sciezka() { }
    
    /*!
     * \brief Destruktor.
     *
     * Destruktor.
     */
    ~Sciezka() { }
};

#endif
