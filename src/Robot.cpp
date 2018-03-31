#include "Robot.hh"
#include <cmath>

/*!
 * \brief Metoda zmieniajaca wektor ruchu robota.
 *
 * Metoda zmieniajaca wektor ruchu robota.
 * Pozwala aktualizowac jego polozenie.
 * param[in] - wektor o jaki robot zostal przesuniety.
 */
void Robot::RuchRobota(Wektor2D W)
{
    ruch=ruch+W;
}

/*!
 * \brief Metoda aktualizuje kat nachylenie robota wzgledem osi x.
 *
 * Metoda aktualizuje kat nachylenie robota wzgledem osi x.
 * param[in] - kat o jaki zostal obrocony.
 */
void Robot::KorygujKat(double alfa)
{
    kat+=alfa;
    if(kat>=360) kat-=360;
}

/*!
 * \brief Konstruktor.
 *
 * Konstruktor.
 */
Robot::Robot()
{
    /* Poczatkowo robot jest skierowany rownolegle do osi x. */
    kat=0;
    /* Wektor ruch inicjujemy wartosciami o jakie nasz robot jest przesuniety wzgledem poczatkowego polozenia w srodku ukladu. */
    ruch[0]=20; ruch[1]=20;
    /* Wektory A, B, C, D, E, Sr reprezentuja wspolrzedne nowego robota. */
    Wektor2D A,B,C,D,E,Sr;
    A[0]=-6;          A[1]=-10;
    B[0]=5;           B[1]=-10;
    C[0]=5*sqrt(2); C[1]=0;
    D[0]=5;           D[1]=10;
    E[0]=-6;          E[1]=10;
    Sr[0]=0;          Sr[1]=0;
    Tab_Wierzcholkow.DodajWierzcholek(A);
    Tab_Wierzcholkow.DodajWierzcholek(B);
    Tab_Wierzcholkow.DodajWierzcholek(C);
    Tab_Wierzcholkow.DodajWierzcholek(D);
    Tab_Wierzcholkow.DodajWierzcholek(E);
    Tab_Wierzcholkow.DodajWierzcholek(Sr);
}

/*!
 * \brief Konstruktor z argumentami.
 *
 * Konstruktor z argumentami.
 * param[in] - r1 - pierwsza wspolrzedna wektora ruchu nowego robota.
 * param[in] - r2 - druga wspolrzedna wektora ruchu nowego robota.
 */
Robot::Robot(float r1, float r2)
{
    /* Poczatkowo robot jest skierowany rownolegle do osi x. */
    kat=0;
    /* Wektor ruch inicjujemy wartosciami o jakie nasz robot jest przesuniety wzgledem poczatkowego polozenia w srodku ukladu. */
    ruch[0]=r1; ruch[1]=r2;
    /* Wektory A, B, C, D, E, Sr reprezentuja wspolrzedne nowego robota. */
    Wektor2D A,B,C,D,E,Sr;
    A[0]=-6;          A[1]=-10;
    B[0]=5;           B[1]=-10;
    C[0]=5*sqrt(2); C[1]=0;
    D[0]=5;           D[1]=10;
    E[0]=-6;          E[1]=10;
    Sr[0]=0;          Sr[1]=0;
    Tab_Wierzcholkow.DodajWierzcholek(A);
    Tab_Wierzcholkow.DodajWierzcholek(B);
    Tab_Wierzcholkow.DodajWierzcholek(C);
    Tab_Wierzcholkow.DodajWierzcholek(D);
    Tab_Wierzcholkow.DodajWierzcholek(E);
    Tab_Wierzcholkow.DodajWierzcholek(Sr);
}

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Robot.
 *
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Robot.
 * Pozwala wypisac na wyjscie wektory reprezentujace wspolrzedne wierzcholkow.
 * param[in] - StrmWy - referencja do strumiena wyjsciowego.
 * param[in] - R - referencja do robota ktorego elementy chcemy wypisac.
 */
std::ostream& operator << (std::ostream &Strm,const Robot& R)
{
    return Strm << R[0] << "  " << R[1] << "  " << R[2] << "  " << R[5] << "  "
    << R[2] << "  " << R[3] << "  " << R[4] << "  " << R[0] << std::endl;
}
