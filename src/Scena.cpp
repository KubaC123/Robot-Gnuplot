#include "Scena.hh"
#include <cstring>
#include <iomanip>
#include <unistd.h>
#include <cmath>

/*!
 * Zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void Scena::ZapisWspolrzednychDoStrumienia(std::ostream& StrmWy)
{
    unsigned int i, j;
    for(j=0; j<RozmiarTablicyObiektow(); j++)
    {
        /* Czy obiekt jest robotem? */
        if(Obiekty2D[j]->RozmiarObiektu()==6)
        {
            
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[0];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[1];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[2];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[5];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[2];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[3];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[4];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[0];
            StrmWy << std::endl << std::endl; /* Dodajemy pusta linie zeby gnuplot rozroznial obiekty. */
        }
        /* Czy obiekt jest przeszkoda? */
        else if(Obiekty2D[j]->RozmiarObiektu()==4)
        {
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[0];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[1];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[2];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[3];
            StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[0];
            StrmWy << std::endl << std::endl;
        }
        else /* Obiekt jest sciezka. */
        {
            for(i=0; i<Obiekty2D[j]->RozmiarObiektu(); i++)
                StrmWy << std::fixed << std::setprecision(10) << (*Obiekty2D[j])[i];
            StrmWy << std::endl << std::endl;
        }
    }
}

/*!
 * Zapis wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Scena::ZapisWspolrzednychDoPliku(const char  *sNazwaPliku)
{
    std::ofstream  StrmPlikowy;
    
    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
        << ":(  nie powiodla sie." << std::endl;
        return false;
    }
    
    ZapisWspolrzednychDoStrumienia(StrmPlikowy);
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

/*!
 * \brief Konstruktor.
 *
 * Konstruktor.
 * Tworzy ustawienie poczatkowe sceny.
 * Trzy roboty oraz trzy przeszkody.
 */
Scena::Scena()
{
    /* Tworzymy wskaznik na pierwszego robota. */
    Robot_Ptr Robot1 = std::make_shared<Robot>();
    
    /* Dodajemy go do kontenera robotow. */
    Roboty.push_back(Robot1);
    
    /* Tworzymy wskaznik na pierwszy obiekt, ktory jest wizualizacja pierwszego robota. */
    Obiekt2D_Ptr Obiekt2D_1 = std::make_shared<Obiekt2D>();
    
    /* Dodajemy go do kontenera obiektow. */
    Obiekty2D.push_back(Obiekt2D_1);
    
    /* Tworzymy wskaznik na drugi obiekt, ktory jest wizualizacja sciezki dla pierwszego robota. */
    Obiekt2D_Ptr Obiekt2D_2 = std::make_shared<Obiekt2D>();
    
    /* Dodajemy go do kontenera obiektow. */
    Obiekty2D.push_back(Obiekt2D_2);
    
    /* Dodajemy wierzcholki do pierwszego obiektu reprezentujacego robota. */
    /* Domyslnie w konstruktorze robota wektor ruchu = (20, 20). */
    for(int i=0; i<6; i++)
    {
        Obiekty2D[0]->DodajWierz((*Roboty[0])[i] + Roboty[0]->Ruch());
    }
    
    /* Dodajemy pierwsza wspolrzedna sciezki, czyli srodek nowego robota */
    Obiekty2D[1]->DodajWierz(Obiekty2D[0]->operator[](5));
    
    /* Powtarzamy powyzszy proces tworzac dwa nastepne roboty o innych wektorach poczatkowych ruchu. */
    
    /* Drugi robot. */
    Robot_Ptr Robot2 = std::make_shared<Robot>(20, 80);
    Roboty.push_back(Robot2);
    Obiekt2D_Ptr Obiekt2D_3 = std::make_shared<Obiekt2D>();
    Obiekt2D_Ptr Obiekt2D_4 = std::make_shared<Obiekt2D>();
    Obiekty2D.push_back(Obiekt2D_3);
    Obiekty2D.push_back(Obiekt2D_4);
    for(int i=0; i<6; i++)
    {
        Obiekty2D[2]->DodajWierz((*Roboty[1])[i] + Roboty[1]->Ruch());
    }
    /* Dodajemy pierwsza wspolrzedna sciezki, czyli srodek nowego robota */
    Obiekty2D[3]->DodajWierz(Obiekty2D[2]->operator[](5));
    
    /* Trzeci Robot. */
    Robot_Ptr Robot3 = std::make_shared<Robot>(140, 20);
    Roboty.push_back(Robot3);
    Obiekt2D_Ptr Obiekt2D_5 = std::make_shared<Obiekt2D>();
    Obiekt2D_Ptr Obiekt2D_6 = std::make_shared<Obiekt2D>();
    Obiekty2D.push_back(Obiekt2D_5);
    Obiekty2D.push_back(Obiekt2D_6);
    for(int i=0; i<6; i++)
    {
        Obiekty2D[4]->DodajWierz((*Roboty[2])[i] + Roboty[2]->Ruch());
    }
    /* Dodajemy pierwsza wspolrzedna sciezki, czyli srodek nowego robota */
    Obiekty2D[5]->DodajWierz(Obiekty2D[4]->operator[](5));

    
    /* Tworzymy przeszkody. */
    Przeszkoda_Ptr Przeszkoda1 = std::make_shared<Przeszkoda>(Wektor2D(50, 100), 30, 20);
    Przeszkoda_Ptr Przeszkoda2 = std::make_shared<Przeszkoda>(Wektor2D(70, 20), 10, 30);
    Przeszkoda_Ptr Przeszkoda3 = std::make_shared<Przeszkoda>(Wektor2D(140, 90), 40 ,40);
    
    /* Dodajemy je do kontenera przeszkod. */
    Przeszkody.push_back(Przeszkoda1);
    Przeszkody.push_back(Przeszkoda2);
    Przeszkody.push_back(Przeszkoda3);
    
    /* Tworzymy wskazniki na obiekt, ktore sa wizualizacjami przeszkod. */
    Obiekt2D_Ptr Obiekt2D_7 = std::make_shared<Obiekt2D>();
    Obiekt2D_Ptr Obiekt2D_8 = std::make_shared<Obiekt2D>();
    Obiekt2D_Ptr Obiekt2D_9 = std::make_shared<Obiekt2D>();
    
    /* Dodajemy je do kontenera obiektow. */
    Obiekty2D.push_back(Obiekt2D_7);
    Obiekty2D.push_back(Obiekt2D_8);
    Obiekty2D.push_back(Obiekt2D_9);
    
    /* Dodajemy wierzcholki. */
    for(int i=0; i<4; i++)
    {
        Obiekty2D[6]->DodajWierz((*Przeszkody[0])[i]);
    }

    
    for(int i=0; i<4; i++)
    {
        Obiekty2D[7]->DodajWierz((*Przeszkody[1])[i]);
    }
    
    for(int i=0; i<4; i++)
    {
        Obiekty2D[8]->DodajWierz((*Przeszkody[2])[i]);
    }
    
    /* Ustawiamy zakres osi, dodajemy nazwy plikow z ktorych gnuplot rysuje, zapisujemy wierzcholki do plikow, rysujemy. */
    Lacze.UstawZakresX(-30, 320);
    Lacze.UstawZakresY(-30, 320);
    Lacze.DodajNazwePliku("Wspolrzedne.dat", PzG::RR_Ciagly, 2);
    Lacze.ZmienTrybRys(PzG::TR_2D);
    ZapisWspolrzednychDoPliku("Wspolrzedne.dat");
    Lacze.Rysuj();
}

/*!
 * \brief Metoda sprawdza czy podczas ruchu dochodzi do kolizji.
 *
 * Metoda sprawdza czy podczas ruchu dochodzi do kolizji.
 * param[in] - numer robota, ktory sie porusza.
 */
bool Scena::Kolizja(int nr)
{
    /* W kontenerze obiektow robota 1 reprezenetuje obiekt[0].
     robota 2, obiekt[2],
     robota 3, obiekt[4]. */
    int nr_obiektu=0;
    if(nr==1) nr_obiektu=0;
    if(nr==2) nr_obiektu=2;
    if(nr==3) nr_obiektu=4;
    
    float promien_kolizji = 5*sqrt(2);
    /* Z przeszkoda 1 */
    if((*Obiekty2D[nr_obiektu])[5][0] > 50-promien_kolizji && (*Obiekty2D[nr_obiektu])[5][0] < 80+promien_kolizji
       && (*Obiekty2D[nr_obiektu])[5][1] > 100-promien_kolizji && (*Obiekty2D[nr_obiektu])[5][1] < 120+promien_kolizji) return true;
    /* Z przeszkoda 2 */
    if((*Obiekty2D[nr_obiektu])[5][0] > 70-promien_kolizji && (*Obiekty2D[nr_obiektu])[5][0] < 80+promien_kolizji
       && (*Obiekty2D[nr_obiektu])[5][1] > 20-promien_kolizji && (*Obiekty2D[nr_obiektu])[5][1] < 50+promien_kolizji) return true;
    /* Z przeszkoda 3 */
    if((*Obiekty2D[nr_obiektu])[5][0] > 140-promien_kolizji && (*Obiekty2D[nr_obiektu])[5][0] < 180+promien_kolizji
       && (*Obiekty2D[nr_obiektu])[5][1] > 90-promien_kolizji && (*Obiekty2D[nr_obiektu])[5][1] < 130+promien_kolizji) return true;
    
    else return false;
}

/*!
 * \brief Metoda pozwalajaca zmienic wektor ruchu wybranego robota.
 *
 * Metoda pozwalajaca zmienic wektor ruchu wybranego robota.
 * param[in] - numer robota.
 */
void Scena::PrzesunRobota(int nr)
{
    Wektor2D W;
    W[0]=cos(M_PI/180*Roboty[nr-1]->Kat());
    W[1]=sin(M_PI/180*Roboty[nr-1]->Kat());
    Roboty[nr-1]->RuchRobota(W);
}

/*!
 * \brief Metoda pozwalajaca zmienic kat nachylenia wybranego robota.
 *
 * Metoda pozwalajaca zmienic kat nachylenia wybranego robota wzgledm osi x.
 * param[in] - nr - numer robota.
 * param[in] - alfa - kat obrotu.
 */
void Scena::ObrocRobota (int nr, double alfa)
{
    Roboty[nr-1]->KorygujKat(alfa);
}

/*!
 * \brief Metoda realizuje animacje ruchu robota.
 *
 * Metoda pozwalajaca zmienic kat nachylenia wybranego robota wzgledm osi x.
 * param[in] - nr - numer robota.
 * param[in] - droga - droga jaka ma przebyc.
 * param[in] - predkosc - predkosc ruchu.
 */
void Scena::AnimujRuch (int nr, float droga, float predkosc)
{
    /* W kontenerze obiektow robota 1 reprezenetuje obiekt[0].
       robota 2, obiekt[2],
       robota 3, obiekt[4]. */
    int nr_obiektu=0;
    if(nr==1) nr_obiektu=0;
    if(nr==2) nr_obiektu=2;
    if(nr==3) nr_obiektu=4;
    
    /* W kontenerze obiektow sciezke robota 1 reprezenetuje obiekt[1].
     robota 2, obiekt[3],
     robota 3, obiekt[5]. */
    int nr_sciezki=0;
    if(nr==1) nr_sciezki=1;
    if(nr==2) nr_sciezki=3;
    if(nr==3) nr_sciezki=5;
    
    float i,j;
    Wektor2D Wek;
    Macierz2x2 M;
    
    M=Obiekty2D[nr_obiektu]->StworzMacierzRotacji(M, Roboty[nr-1]->Kat());
    Wek[0]=cos(M_PI/180*Roboty[nr-1]->Kat());
    Wek[1]=sin(M_PI/180*Roboty[nr-1]->Kat());
    for (i=0; i< droga; i++)
      {
        PrzesunRobota(nr);
        for(j=0; j<6; j++)
        {
            /*
            std::cout << "Wierzcholek " << j << " Robota" << Roboty[nr-1]->operator[](j) << std::endl;
            std::cout << "Wektor ruchu Robota " << Roboty[nr-1]->Ruch() << std::endl;
            std::cout << "Wek Trans Obiektu " << Obiekty2D[nr_obiektu]->Translacyjny() << std::endl;
            std::cout << "Wierzcholek " << j << " Przed obrotem " << Obiekty2D[nr_obiektu]->operator[](j)<< std::endl;
             */
            (*Obiekty2D[nr_obiektu])[j]=M*(*Roboty[nr-1])[j]+Roboty[nr-1]->Ruch()+Wek+Obiekty2D[nr_obiektu]->Translacyjny();
            //std::cout << "Wierzcholek " << j << " Po obrocie " << Obiekty2D[nr_obiektu]->operator[](j)<< std::endl;
        }
          
        if(Kolizja(nr_obiektu))
        {
            std::cout << "Ruch zostaje przerwany!!! Ryzyko kolizji!!!" << std::endl;
            break;
        }
	
        /* Jako kolejna wspolrzedna sciezki zapisujemy nowy srodek robota. */
        Obiekty2D[nr_sciezki]->DodajWierz((*Obiekty2D[nr_obiektu])[5]);
        ZapisWspolrzednychDoPliku("Wspolrzedne.dat");
        Lacze.Rysuj();
        usleep(2000);
    }
}

/*!
 * \brief Metoda realizuje animacje obrotu robota.
 *
 * Metoda realizuje animacje obrotu robota.
 * param[in] - nr - numer robota.
 * param[in] - alfa - kat obrotu.
 */
void Scena::AnimujObrot (int nr, double alfa)
{
    /* W kontenerze obiektow robota 1 reprezenetuje obiekt[0].
     robota 2, obiekt[2],
     robota 3, obiekt[4]. */
    int nr_obiektu=0;
    if(nr==1) nr_obiektu=0;
    if(nr==2) nr_obiektu=2;
    if(nr==3) nr_obiektu=4;
    
    Macierz2x2 M;
    int i;
    double roznica=Roboty[nr-1]->Kat()-alfa;
    for(alfa=0; roznica<Roboty[nr-1]->Kat(); roznica++)
    {
        M=Obiekty2D[nr_obiektu]->StworzMacierzRotacji(M, roznica);
        for(i=0; i<6; i++)
        {
            (*Obiekty2D[nr_obiektu])[i]=M*(*Roboty[nr-1])[i]+Roboty[nr-1]->Ruch()+Obiekty2D[nr_obiektu]->Translacyjny();
        }
        ZapisWspolrzednychDoPliku("Wspolrzedne.dat");
        Lacze.Rysuj();
        usleep(2000);
    }
}

/*!
 * \brief Metoda pozwala na translacje sceny.
 *
 * Metoda pozwala na translacje sceny. Przemiesza wszystkie obiekty.
 * param[in] - zadany wektor translacji
 */
void Scena::TranslacjaSceny (Wektor2D W)
{
    unsigned int i, j;
    
    for(j=0; j<RozmiarTablicyObiektow(); j++)
    {
        Obiekty2D[j]->Translacyjny()=W;
        for (i=0; i<Obiekty2D[j]->RozmiarObiektu(); i++)
        {
            (*Obiekty2D[j])[i]=(*Obiekty2D[j])[i]+W;
        }
    }
    ZapisWspolrzednychDoPliku("Wspolrzedne.dat");
    Lacze.Rysuj();
}


/*!
 * \brief Metoda przywraca ustawienia poczatkowe sceny.
 *
 * Metoda przywraca ustawienia poczatkowe sceny.
 */
void Scena::UstawieniePoczatkowe ()
{
    /* W kontenerze obiektow robota 1 reprezenetuje obiekt[0].
     robota 2, obiekt[2],
     robota 3, obiekt[4]. */
    
    /* W kontenerze obiektow sciezke robota 1 reprezenetuje obiekt[1].
     robota 2, obiekt[3],
     robota 3, obiekt[5]. */
    
    /* Dla robota 1. */
    unsigned int i;
    Wektor2D W1, W2;
    W1=Wektor2D(20, 20);
    W2=Wektor2D(0, 0);
    Obiekty2D[0]->Translacyjny()=W2;
    Roboty[0]->Kat()=0;
    Roboty[0]->Ruch()=W1;
    for(i=0; i<6; i++)
    {
        (*Obiekty2D[0])[i]=(*Roboty[0])[i]+W1;
    }
    for(i=0; i<Obiekty2D[1]->RozmiarObiektu(); i++)
    {
        (*Obiekty2D[1])[i]=(*Obiekty2D[0])[5];
    }
    
    /* Dla robota 2. */
    W1=Wektor2D(20, 80);
    W2=Wektor2D(0, 0);
    Obiekty2D[2]->Translacyjny()=W2;
    Roboty[1]->Kat()=0;
    Roboty[1]->Ruch()=W1;
    for(i=0;i<6;i++)
    {
        (*Obiekty2D[2])[i]=(*Roboty[1])[i]+W1;
    }
    for(i=0;i<Obiekty2D[3]->RozmiarObiektu();i++)
    {
        (*Obiekty2D[3])[i]=(*Obiekty2D[2])[5];
    }
    
    /* Dla robota 3. */
    W1=Wektor2D(140, 20);
    W2=Wektor2D(0, 0);
    Obiekty2D[4]->Translacyjny()=W2;
    Roboty[2]->Kat()=0;
    Roboty[2]->Ruch()=W1;
    for(i=0;i<6;i++)
    {
        (*Obiekty2D[4])[i]=(*Roboty[2])[i]+W1;
    }
    for(i=0;i<Obiekty2D[5]->RozmiarObiektu();i++)
    {
        (*Obiekty2D[5])[i]=(*Obiekty2D[4])[5];
    }
    ZapisWspolrzednychDoPliku("Wspolrzedne.dat");
    Lacze.Rysuj();
}

/*!
 * \brief Metoda pozwala pobrac srodek wybranego robota.
 *
 * Metoda pozwala pobrac srodek wybranego robota.
 * param[in] - numer robota, ktorego srodek chcemy pobrac.
 */
Wektor2D Scena::PobierzSrodek(int nr_robota)
{
    switch (nr_robota)
    {
            case 1:
            return (*Obiekty2D[0])[5];
            break;
            
            case 2:
            return (*Obiekty2D[2])[5];
            break;
            
            case 3:
            return (*Obiekty2D[4])[5];
            break;
            
            default:
            std::cerr << "Blad. Nie ma robota o tym numerze." << std::endl;
            break;
    }
    return Wektor2D();
}


