#ifndef ROBOT_HH
#define ROBOT_HH
#include "Obiekt2D.hh"

/*!
 * \file Robot.hh
 *  Plik zawiera definicje klasy Robot,
 *  ktora modeluje robota jako obiekt w dwuwymiarowym ukladzie wspolrzednych.
 */


/*!
 * \brief Klasa modeluje robota.
 *
 * Klasa modeluje robota jako obiekt w dwuwymiarowym ukladzie wspolrzednych.
 * Dziedziczy z klasy Obiekt2D.
 * Zawiera atrybuty charakteryzujace robota oraz odpowiednie metody pozwalajace na prawidlowe sterowanie.
 */

class Robot: public Obiekt2D
{
    /* Tablica przechowujaca wspolrzedne wierzcholkow robota */
    Wierzcholki Tab_Wierzcholkow;
    /* Wektor ruchu robota od polozenia, w ktorym jego srodek znajduje sie w poczatku ukladu wspolrzednych.
    Pomaga w wizualizacji ruchow w gnuplocie. */
    Wektor2D ruch;
    /* Kat nachylenia robota wzgledem osi x. */
    double kat;
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
     * \brief Metoda zmieniajaca wektor ruchu robota.
     * 
     * Metoda zmieniajaca wektor ruchu robota.
     * Pozwala aktualizowac jego polozenie.
     * param[in] - wektor o jaki robot zostal przesuniety. 
     */
    void RuchRobota(Wektor2D W);
    
    /*!
     * \brief Metoda zwraca kat nachylenia robota wzgledem osi x.
     *
     * Metoda zwraca kat nachylenia robota wzgledem osi x.
     */
    double& Kat() { return kat; }
    
    /*!
     * \brief Metoda zwraca wektor ruchu robota.
     *
     * Metoda zwraca wektor ruchu robota.
     */
    Wektor2D& Ruch() { return ruch; }
    
    /*!
     * \brief Metoda aktualizuje kat nachylenie robota wzgledem osi x.
     *
     * Metoda aktualizuje kat nachylenie robota wzgledem osi x.
     * param[in] - kat o jaki zostal obrocony.
     */
    void KorygujKat(double alfa);
    
    /*!
     * \brief Metoda pozwalajaca zidentyfikowac robota.
     *
     * Metoda pozwalajaca zidentyfikowac robota.
     */
    const char* NazwaObiektu() const { return "Robot"; }
    
    /*!
     * \brief Konstruktor.
     *
     * Konstruktor.
     */
    Robot();
    
    /*!
     * \brief Konstruktor z argumentami.
     *
     * Konstruktor z argumentami.
     * param[in] - r1 - pierwsza wspolrzedna wektora ruchu nowego robota.
     * param[in] - r2 - druga wspolrzedna wektora ruchu nowego robota.
     */
    Robot(float r1, float r2);
    
    /*!
     * \brief Destruktor.
     *
     * Destruktor.
     */
    ~Robot() { }
};

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Robot.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Robot.
 * Pozwala wypisac na wyjscie wektory reprezentujace wspolrzedne wierzcholkow.
 * param[in] - StrmWy - referencja do strumiena wyjsciowego.
 * param[in] - R - referencja do robota ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm, const Robot& R);

#endif
