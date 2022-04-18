#pragma once
#include <iostream>
#include <memory>
#include"Funkcije.h"
using namespace std;
//Kolekcija elemenata (tip T) sa mogucnoscu dinamickog prosirivanja
template<class T>
class DinamickaKolekcija {
private:
	int _trenutno; //oznacava velicinu niza
	int _maxElemenata;
	T* _elementi;
public:
	//Z2.1
	DinamickaKolekcija(int maxElemenata = 100) {
		_trenutno = 0;
		_maxElemenata = maxElemenata;
		_elementi = new T[_maxElemenata];
	}
	//Z2.2
	DinamickaKolekcija(const DinamickaKolekcija<T>& kolekcija) {
		_trenutno = kolekcija._trenutno;
		_maxElemenata = kolekcija._maxElemenata;
		_elementi = new T[_maxElemenata];
		for (int i = 0; i < _trenutno; i++) {
			_elementi[i] = kolekcija._elementi[i];
		}
	}
	//Z2.3
	DinamickaKolekcija(DinamickaKolekcija<T>&& kolekcija) {
		_trenutno = kolekcija._trenutno;
		kolekcija._trenutno = 0;
		_maxElemenata = kolekcija._maxElemenata;
		kolekcija._maxElemenata = 0;
		_elementi = kolekcija._elementi;
		kolekcija._elementi = nullptr;

	}
	//Z2.4
	DinamickaKolekcija<T>& operator = (const DinamickaKolekcija<T>& kolekcija) {
		if (this == &kolekcija)
			return *this;
		_trenutno = kolekcija._trenutno;
		_maxElemenata = kolekcija._maxElemenata;
		_elementi = new T[_maxElemenata];
		for (int i = 0; i < _trenutno; i++) {
			_elementi[i] = kolekcija._elementi[i];
		}
		return *this;
	}

	//Z2.5 :: Osigurati da je index unutar opsega [0,_trenutno-1]. Koristiti genericke funkcije 'Min' i 'Max' 
	T& operator [] (int index) const {
		index = Min(index, _trenutno - 1);
		index = Max(index, 0);
		return _elementi[index];
	}

	//Z2.6
	void ProsiriKolekciju(int prosiriZa) {
		T* temp = _elementi;
		_maxElemenata += prosiriZa;
		_elementi = new T[_maxElemenata];
		for (int i = 0; i < _trenutno; i++)
		{
			_elementi[i] = temp[i];
		}
		delete temp; temp = nullptr;


	}

	//Z2.7 :: Dodavanje novog elementa (ukoliko je _trenutno < _maxElemenata, uraditi prosirivanje niza za 10)
	bool operator += (T noviElement) {
		if (_maxElemenata == _trenutno)
			ProsiriKolekciju(10);
		_elementi[_trenutno++] = noviElement;
		return true;
	}

	//Z2.8
	bool UkloniZadnjiElement() {
		if (_trenutno == 0)
			return false;
		_trenutno--;
		return true;
	}
	//Z2.9
	int GetTrenutno() const { return _trenutno; }
	int GetMaxElemenata() const { return _maxElemenata; }

	~DinamickaKolekcija() {
		delete[] _elementi;
		_elementi = nullptr;
	}
	friend ostream& operator << <> (ostream& COUT, const DinamickaKolekcija<T>& kolekcija);
};
//Z2.10 :: Ispisuje elemente kolekcije. Za pristup elementima koristiti preklopljeni operator []
template<class T>
ostream& operator << <>(ostream& COUT, const DinamickaKolekcija<T>& kolekcija) {
	for (int i = 0; i < kolekcija.GetTrenutno(); i++)
	{
		COUT << "|" << kolekcija[i] << "|";
		return COUT;
	}
}
