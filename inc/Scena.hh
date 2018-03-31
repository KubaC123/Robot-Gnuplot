#ifndef SCENA_HH
#define SCENA_HH
#include "Robot.hh"
#include "Sciezka.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"
#include <fstream>
#include <memory>

/*!
 * \file Scena.hh
 *  Plik zawiera definicje klasy Scena,
 *  ktora pozwala na przechowywanie i operowanie na obiekatach ktore maja byc wyswietlane.
 */

/* typedef pozwalajacy na czytelne poslugiwanie sie smart pointerami. */
typedef std::shared_ptr<Robot> Robot_Ptr;
typedef std::shared_ptr<Obiekt2D> Obiekt2D_Ptr;
typedef std::shared_ptr<Przeszkoda> Przeszkoda_Ptr;

/*!
 * \brief Klasa modeluje scene jako zbior obiektow.
 *
 * Klasa modeluje scene jako zbior obiektow.
 * Pozwala na przechowywanie obiektow, i operacje na nich.
 * Umozliwia wizualizacje ruchow i obrotow w programie gnuplot.
 */
class Scena
{
    std::vector<Robot_Ptr> Roboty;
    std::vector<Obiekt2D_Ptr> Obiekty2D;
    std::vector<Przeszkoda_Ptr> Przeszkody;
    PzG::LaczeDoGNUPlota Lacze;
public:
    /*!
     * \brief Metoda zwracajaca rozmiar tablicy obiektow.
     *
     * Metoda zwracajaca rozmiar tablicy obiektow.
     */
    unsigned int RozmiarTablicyObiektow() const { return (int)Obiekty2D.size(); }
    
    /*!
     * Zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
     * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
     * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
     * to 16 miejsc, sposób wyrównywania - do prawej strony.
     * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
     * \retval true - gdy operacja zapisu powiodła się,
     * \retval false - w przypadku przeciwnym.
     */
    void ZapisWspolrzednychDoStrumienia(std::ostream& StrmWy);
    
    /*!
     * Zapis wspolrzednych zbioru punktow do pliku, z ktorego
     * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
     * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
     * \retval true - gdy operacja zapisu powiodła się,
     * \retval false - w przypadku przeciwnym.
     */
    bool ZapisWspolrzednychDoPliku(const char  *sNazwaPliku);
    
    /*! 
     * \brief Konstruktor.
     *
     * Konstruktor.
     * Tworzy ustawienie poczatkowe sceny. 
     * Trzy roboty oraz trzy przeszkody.
     */
    Scena();
    
    /*!
     * \brief Metoda sprawdza czy podczas ruchu dochodzi do kolizji.
     *
     * Metoda sprawdza czy podczas ruchu dochodzi do kolizji.
     * param[in] - numer robota, ktory sie porusza.
     */
    bool Kolizja(int nr);
    
    /*!
     * \brief Destruktor.
     *
     * Destruktor.
     */
    ~Scena() {}
    
    /*! 
     * \brief Metoda pozwalajaca zmienic wektor ruchu wybranego robota.
     *
     * Metoda pozwalajaca zmienic wektor ruchu wybranego robota.
     * param[in] - numer robota.
     */
    void PrzesunRobota(int nr);
    
    /*!
     * \brief Metoda pozwalajaca zmienic kat nachylenia wybranego robota.
     *
     * Metoda pozwalajaca zmienic kat nachylenia wybranego robota wzgledm osi x.
     * param[in] - nr - numer robota.
     * param[in] - alfa - kat obrotu.
     */
    void ObrocRobota(int nr, double alfa);
    
    /*!
     * \brief Metoda realizuje animacje ruchu robota.
     *
     * Metoda realizuje animacje ruchu robota.
     * param[in] - nr - numer robota.
     * param[in] - droga - droga jaka ma przebyc.
     * param[in] - predkosc - predkosc ruchu.
     */
    void AnimujRuch(int nr, float droga, float predkosc);
    
    /*!
     * \brief Metoda realizuje animacje obrotu robota.
     *
     * Metoda realizuje animacje obrotu robota.
     * param[in] - nr - numer robota.
     * param[in] - alfa - kat obrotu.
     */
    void AnimujObrot(int nr, double alfa);
    
    /*!
     * \brief Metoda pozwala na translacje sceny.
     *
     * Metoda pozwala na translacje sceny. Przemiesza wszystkie obiekty.
     * param[in] - zadany wektor translacji
     */
    void TranslacjaSceny(Wektor2D W);
    
    /*!
     * \brief Metoda przywraca ustawienia poczatkowe sceny.
     *
     * Metoda przywraca ustawienia poczatkowe sceny.
     */
    void UstawieniePoczatkowe ();
    
    /*!
     * \brief Metoda pozwala pobrac srodek wybranego robota.
     *
     * Metoda pozwala pobrac srodek wybranego robota.
     * param[in] - numer robota, ktorego srodek chcemy pobrac.
     */
    Wektor2D PobierzSrodek(int nr_robota);
};

#endif
