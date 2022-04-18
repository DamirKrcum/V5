#include <iostream>
#include <memory>
#include "Datum.h"
#include "DKolekcija.h"
#include "Par.h"
#include "Sahista.h"
#include "SKolekcija.h"
#include "Turnir.h"
#include "Funkcije.h"
using namespace std;

void Zadatak1() {
    Datum aprilFoolsDay;
    Datum laborDay(1, 5, 2021);
    Datum newYearsEve(31, 12, 2021);
    aprilFoolsDay.SetDan(1);
    aprilFoolsDay.SetMjesec(4);
    aprilFoolsDay.SetGodina(2021);

    Datum d1(aprilFoolsDay);
    Datum d2(move(laborDay));
    Datum d3;
    d3 = newYearsEve;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << "Dealokacija..." << endl;
}

void Zadatak2() {
    cout << "Kolekcija datuma..." << endl;
    DinamickaKolekcija<Datum> datumi;
    cout << "Dodajemo 5 elemenata: " << endl;
    datumi += Datum(1, 5, 2020);
    datumi += Datum(7, 7, 2020);
    datumi += Datum(1, 3, 2020);
    datumi += Datum(7, 10, 2020);
    datumi += Datum(8, 12, 2020);
    cout << "Ispis elemenata..." << endl;
    cout << datumi << endl;
    cout << "Uklanjamo zadnji element...." << endl;
    datumi.UkloniZadnjiElement();
    cout << datumi << endl;
   
    cout << "Pravimo kopiju kolekcije: " << endl;
    DinamickaKolekcija<Datum> kopijaDatuma(datumi);
    cout << "Dodajemo jedan element (11.3.2019)" << endl;
    kopijaDatuma += Datum(11, 3, 2019);
    cout << kopijaDatuma << endl;
   
    cout << "Zatim premjestamo elemente (iz kopije) na novu lokaciju..." << endl;
    DinamickaKolekcija<Datum> noviDatumi(move(kopijaDatuma));
    cout << "Ispis nakon premjestanja elemenata..." << endl;
    cout << noviDatumi << endl;
   
    cout << "Kreiramo novu kolekciju i vrsimo naknadno kopiranje.. " << endl;
    DinamickaKolekcija<Datum> nova;
    nova = noviDatumi;
    cout << nova << endl;
    cout << "Dealokacija..." << endl;
}

void Zadatak3() {
   cout << "Kreiramo 'tudjeOcjene'" << endl;
   cout << "Dodajemo nove elemente u 'tudjeOcjene'..." << endl;
   StatickaKolekcija<int, 100> tudjeOcjene;
   tudjeOcjene += 9;
   tudjeOcjene += 10;
   tudjeOcjene += 10;
   tudjeOcjene += 10;
   tudjeOcjene += 9;
   tudjeOcjene += 10;
   tudjeOcjene += 10;
   cout << tudjeOcjene << endl;
   
   cout << "Kreiramo 'mojeOcjene' na osnovu 'tudjeOcjene'" << endl;
   StatickaKolekcija<int, 100> mojeOcjene(tudjeOcjene);
   cout << mojeOcjene << endl;
   cout << "Brisemo sve elemente iz 'mojeOcjene'" << endl;
   for (size_t i = 0; i < 10; i++)
       mojeOcjene.UkloniZadnjiElement();
   cout << "Dodajemo nove (losije) ocjene u 'mojeOcjene'  .... " << endl;
   mojeOcjene += 6;
   mojeOcjene += 7;
   mojeOcjene += 6;
   mojeOcjene += 6;
   mojeOcjene += 7;
   mojeOcjene += 8;
   cout << mojeOcjene << endl;
   
   cout << "Kreiramo 'josGoreOcjene' na osnovu 'mojeOcjene' " << endl;
   StatickaKolekcija<int, 100> josGoreOcjene(move(mojeOcjene));
   cout << josGoreOcjene << endl;
   cout << "Brisemo sve elemente iz 'josGoreOcjene'..." << endl;
   for (size_t i = 0; i < 10; i++)
       josGoreOcjene.UkloniZadnjiElement();
   cout << "Dodajemo nove (losije) ocjene u 'josGoreOcjene' .... " << endl;
   for (size_t i = 0; i < 5; i++)
       josGoreOcjene += 6;
   cout << josGoreOcjene << endl;
   
   cout << "Kreiramo 'josGoreOcjene2' na osnovu 'josGoreOcjene' " << endl;
   StatickaKolekcija<int, 100> josGoreOcjene2;
   josGoreOcjene2 = josGoreOcjene;
   cout << josGoreOcjene << endl;
   cout << "Dealokacija..." << endl;
}

void Zadatak4() {
    Sahista s1("Gary Kasparov", Datum(2, 2, 1963), "Rusija", 1);
    Sahista s2(s1);
    Sahista s3(move(s2));
    Sahista garyKasparov;
    garyKasparov = s3;
    
    Sahista bobbyFischer("Bobby Fischer", Datum(4, 4, 1943), "SAD", 1);
    Sahista carlsen("Magnus Carlsen", Datum(3, 3, 1990), "Norveska", 1);
    Sahista judithPolgar("Judith Polgar", Datum(5, 5, 1976), "Madjarska", 0);
    
    DinamickaKolekcija<Sahista> sahisti;
    sahisti += garyKasparov;
    sahisti += bobbyFischer;
    sahisti += carlsen;
    sahisti += judithPolgar;
    
    cout << sahisti << endl;
    cout << "Najmladji sahista: " << endl << (VratiNajmladjegSahistu(sahisti)->GetImePrezime()) << endl;
    cout << "Dealokacija..." << endl;
}

void Zadatak5() {
    Sahista kingBobby("Bobby Fischek", Datum(4, 4, 1943), "SAD", 1);
    Sahista sahmatov("Viktor Sahmatov", Datum(4, 4, 1966), "Rusija", 1);
    Sahista chuckNorris("Chuck Mate", Datum(4, 4, 1966), "SAD", 1);
    SahovskiTurnir bugojno2021("MVST Bugojno (2021)", "Bugojno, BiH");
    bugojno2021.DodajDuel(kingBobby, sahmatov);
    bugojno2021.DodajDuel(sahmatov, chuckNorris);
    bugojno2021.DodajDuel(chuckNorris, kingBobby);
    cout << bugojno2021 << endl;
    cout << "Dealokacija..." << endl;
}
void Menu() {
    int nastaviDalje = 1;
    while (nastaviDalje == 1) {
        int izbor = 0;
        do {
            system("cls");
            cout << "::Zadaci::" << endl;
            cout << "(1) Zadatak 1" << endl;
            cout << "(2) Zadatak 2" << endl;
            cout << "(3) Zadatak 3" << endl;
            cout << "(4) Zadatak 4" << endl;
            cout << "(5) Zadatak 5" << endl;
            cout << "Unesite odgovarajuci broj zadatka za testiranje: -->: ";
            cin >> izbor;
            cout << endl;
        } while (izbor < 1 || izbor > 5);
        switch (izbor) {
        case 1: Zadatak1(); cout << "Zadatak 1. Done." << endl; break;
        case 2: Zadatak2(); cout << "Zadatak 2. Done." << endl; break;
        case 3: Zadatak3(); cout << "Zadatak 3. Done." << endl; break;
        case 4: Zadatak4(); cout << "Zadatak 4. Done." << endl; break;
        case 5: Zadatak5(); cout << "Zadatak 5. Done." << endl; break;
        default:break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
}
int main() {
    Menu();
    return 0;
}


