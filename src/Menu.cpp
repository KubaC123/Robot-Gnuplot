#include "Menu.hh"
#include <iostream>
#include "Scena.hh"

/*!
 * \brief Funkcja wyswielta menu programu.
 *
 * Funkcja wyswielta menu programu.
 */
void WyswietlMenu()
{
    std::cout << "z - zmiana szykosci ruchu robota" << std::endl;
    std::cout << "o - obrot robota" << std::endl;
    std::cout << "j - jazda na wprost" << std::endl;
    std::cout << "s - selekcja robota" << std::endl;
    std::cout << "t - zadaj translacje rysunku" << std::endl;
    std::cout << "p - powrot do pierwotnego ustawienia rysunku" << std::endl;
    std::cout << "w - wyswietl ponownie menu" << std::endl;
    std::cout << "k - zakoncz dzialanie programu" << std::endl;
}

/*!
 * \brief Funkcja pozwala na wykonywanie odpowiednich instrukcji.
 *
 * Funkcja pozwala na wykonywanie odpowiednich instrukcji.
 */
void Menu()
{
    Scena S;
    int nr_robota=1;
    float predkosc=20;
    float droga=0;
    double alfa=0;
    Wektor2D Wektor_Translacji;
    char wybor='a';
    std::cout << "ROBOTY I PRZESZKODY" << std::endl << std::endl ;
    std::cout << "Aktualnie wybranym robotem jest:" << std::endl;
    std::cout << "Robot " << nr_robota << " Wspolrzedne srodka: " << S.PobierzSrodek(nr_robota) << std::endl;
    WyswietlMenu();
    std::cin >> wybor;
    while (wybor!='k')
    {
        switch (wybor)
        {
                case 'z':
                std::cin >> predkosc;
                break;
                
                case 'o':
                std::cout << "Podaj kat obrotu w stopniach" << std::endl;
                std::cin >> alfa;
                S.AnimujObrot(nr_robota, alfa);
                break;
                
                case 'j':
                std::cout << "Podaj dlugosc drogi ruchu robota na wprost" << std::endl;
                std::cin >> droga;
                S.AnimujRuch(nr_robota, droga, predkosc);
                break;
                
                case 's':
                std::cout << "Ktorym robotem chcesz sterowac?" << std::endl;
                std::cin >> nr_robota;
                if(std::cin.fail())
                {
                    std::cerr << "Blad. Nie ma robota o takim numerze." << std::endl;
                    nr_robota=1;
                }
                if (nr_robota>3 || nr_robota<1)
                {
                    std::cerr << "Blad. Nie ma robota o takim numerze." << std::endl;
                    nr_robota=1;
                }
                break;
                
                case 't':
                std::cout << "Podaj wektor translacji w postaci dwoch liczb (x, ,y)" << std::endl;
                std::cin >> Wektor_Translacji;
                if(!std::cin.fail()) S.TranslacjaSceny(Wektor_Translacji);
                break;
                
                case 'p':
                S.UstawieniePoczatkowe();
                break;
                
                case 'w':
                WyswietlMenu();
                break;
                
                case 'k':
                exit(1);
                break;
                
                default:
                std::cerr << "Wybierz sposrod opcji (w - wyswietl ponownie menu)" << std::endl;
                break;
        }
        std::cout << "Aktualnie wybranym robotem jest:" << std::endl;
        std::cout << "Robot " << nr_robota << " Wspolrzedne srodka: " << S.PobierzSrodek(nr_robota) << std::endl << std::endl;
        std::cout << "Twoj wybor? (w - wyswietl ponownie menu)" << std::endl;
        std::cin >> wybor;
    }
}

