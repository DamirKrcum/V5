#pragma once
#include <iostream>
#include <memory>
#include"Funkcije.h"
using namespace std;

template<class T, int max> //max oznacava velicinu niza
class StatickaKolekcija {
private:
	int _trenutno; //trenutno elemenata 
	T* _elementi[max] = { nullptr }; //staticki niz pokazivaca
public:
	//Z3.1
	StatickaKolekcija() {
		_trenutno = 0;

	}
	//Z3.2
	StatickaKolekcija(const StatickaKolekcija<T, max>& kolekcija) {
		_trenutno = kolekcija._trenutno;
		for (size_t i = 0; i < kolekcija._trenutno; i++)
		{
			_elementi[i] = new T(*kolekcija._elementi[i]);  //ne zaboravi dereferencirati clan niza
		}
	}
	//Z3.3
	StatickaKolekcija(StatickaKolekcija<T, max>&& kolekcija) {
		_trenutno = kolekcija._trenutno;

		for (int i = 0; i < _trenutno; i++)
		{
			_elementi[i] = kolekcija._elementi[i];
			kolekcija._elementi[i] = nullptr;
		}
	}

	//Z3.4
	StatickaKolekcija<T, max>& operator=(const StatickaKolekcija<T, max>& kolekcija) {
		if (this == &kolekcija)
			return *this;
		for (int i = 0; i < _trenutno; i++)
		{
			delete _elementi[i];
			_elementi[i] = nullptr;
		}
		_trenutno = kolekcija._trenutno;
		for (size_t i = 0; i < kolekcija._trenutno; i++)
		{
			_elementi[i] = new T(*kolekcija._elementi[i]);  //ne zaboravi dereferencirati clan niza
		}
		return *this;
	}

	//Z3.5 :: Osigurati da je index unutar opsega [0,_trenutno-1]. Koristiti genericke funkcije 'Min' i 'Max' 
	T& operator [] (int index) const {
		index = Min(index, _trenutno - 1);
		index = Max(index, 0);
		return *_elementi[index];
	}

	//Z3.6 :: Dodati (alocirati) novi element
	bool operator +=(T noviElement) {
		if (_trenutno == max)
			return false;
		_elementi[_trenutno++] = new T(noviElement);
		return true;
	}

	//Z3.7 :: Izbrisati (dealocirati) zadnji element i umanjiti brojac
	bool UkloniZadnjiElement() {
		if (_trenutno == 0)
			return false;

		delete _elementi[_trenutno - 1];
		_elementi[_trenutno - 1] = nullptr;
		_trenutno--;
		return true;


	}

	//Z3.8
	int GetTrenutno() const { return _trenutno; }
	int GetMaxElemenata() const { return max; }

	~StatickaKolekcija() {
		for (int i = 0; i < _trenutno; i++)
		{
			delete _elementi[i];
			_elementi[i] = nullptr;
		}
	}

	friend ostream& operator << <>(ostream& COUT, const StatickaKolekcija<T, max>& kolekcija);
};

//Z3.9
template<class T, int max>
ostream& operator << <>(ostream& COUT, const StatickaKolekcija<T, max>& kolekcija) {
	for (int i = 0; i < kolekcija.GetTrenutno(); i++)
	{
		COUT << kolekcija[i] << endl;
	}
		return COUT;
}