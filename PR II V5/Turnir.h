#pragma once
#include <iostream>
#include <memory>
using namespace std;



class SahovskiTurnir {
private:
    char* _naziv;
    char* _mjestoOdrzavanja;
    StatickaKolekcija<Par<Sahista, Sahista>, 20> _dueli;
public:
    //Z5.6
    SahovskiTurnir() {
        _naziv = nullptr;
        _mjestoOdrzavanja = nullptr;
    }
    //Z5.7
    SahovskiTurnir(const char* naziv, const char* mjestoOdrzavanja) {
        _naziv = AlocirajIKopiraj(naziv);
        _mjestoOdrzavanja = AlocirajIKopiraj(mjestoOdrzavanja);
    }
    //Z5.8
    bool DodajDuel(Sahista& s1, Sahista& s2) {
        if (_dueli.GetTrenutno() == 20)
            return false;
        _dueli += Par<Sahista, Sahista>(s1, s2);
        return true;
    }
    //Z5.9
    ~SahovskiTurnir() {
        delete[] _naziv; _naziv = nullptr;
        delete[] _mjestoOdrzavanja; _mjestoOdrzavanja = nullptr;
    }
    friend ostream& operator <<(ostream& COUT, SahovskiTurnir& st);
};
//Z5.10 :: Ispisati naziv, mjesto, te sve duele
ostream& operator <<(ostream& COUT, SahovskiTurnir& st) {
    COUT << "Naziv turnira: " << st._naziv << endl;
    COUT << "Mjesto odrzavanja: " << st._mjestoOdrzavanja << endl;
    COUT << "Dueli: " << endl;
    for (int i = 0; i < st._dueli.GetTrenutno(); i++)
    {
        Sahista Prvi = st._dueli[i].GetLijevi();
        Sahista Drugi = st._dueli[i].GetDesni();
        COUT << "Duel (" << i + 1 << ") " << Prvi.GetImePrezime() << " - " << Drugi.GetImePrezime() << endl;
        
    }
    return COUT;
}