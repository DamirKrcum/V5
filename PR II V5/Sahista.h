#pragma once
#include <iostream>
#include <memory>
#include"Funkcije.h"
using namespace std;
class Sahista {
private:
	const char* _imePrezime;
	Datum _datumRodjenja;
	const char* _drzava;
	shared_ptr<bool> _spol;
public:
	//Z4.1
	Sahista() {
		_imePrezime = nullptr;
		_drzava = nullptr;
	}
	//Z4.2
	Sahista(const char* imePrezime, Datum datumRodjenja, const char* drzava, bool spol)
		: _datumRodjenja(datumRodjenja.GetDan(), datumRodjenja.GetMjesec(), datumRodjenja.GetGodina())
	{
		_imePrezime = AlocirajIKopiraj(imePrezime);
		_drzava = AlocirajIKopiraj(drzava);
		_spol = make_shared<bool>(spol);
	}
	//Z4.3
	Sahista(const Sahista& obj)
		:_datumRodjenja(obj._datumRodjenja)
	{
		_imePrezime = AlocirajIKopiraj(obj._imePrezime);
		_drzava = AlocirajIKopiraj(obj._drzava);
		_spol = make_shared<bool>(obj._spol);
	}
	//Z4.4
	Sahista(Sahista&& obj)
		:_datumRodjenja(move(obj._datumRodjenja))
	{
		_imePrezime = obj._imePrezime;
		obj._imePrezime = nullptr;
		_drzava = obj._drzava;
		obj._drzava = nullptr;
		_spol = obj._spol;
		obj._spol = nullptr;
	}
	//Z4.5
	Sahista& operator = (const Sahista& obj) {
		if (this == &obj)
			return *this;
		delete[] _imePrezime; _imePrezime = nullptr;
		delete[] _drzava; _drzava = nullptr;
		_imePrezime = AlocirajIKopiraj(obj._imePrezime);
		_drzava = AlocirajIKopiraj(obj._drzava);
		if (_spol == nullptr)
			_spol = make_shared<bool>();
		*_spol = *obj._spol;
		_datumRodjenja = obj._datumRodjenja;

		return *this;
	}
	//Z4.6
	const char* GetImePrezime() const { return _imePrezime; }
	const char* GetDrzava() const { return _drzava; }
	Datum GetDatumRodjenja() const { return _datumRodjenja; }
	bool GetSpol() const { return *_spol; }

	//Z4.7
	void SetImePrezime(const char* imePrezime);
	void SetDatumRodjenja(Datum datumRodjenja);
	void SetDrzava(const char* drzava);
	void SetSpol(bool spol);
	//Z4.8
	~Sahista() {
		delete[] _imePrezime; _imePrezime = nullptr;
		delete[] _drzava; _drzava = nullptr;
		_spol.reset();

	}
	friend ostream& operator << (ostream& COUT, const Sahista& s);
	friend bool operator >(const Sahista& obj1, const Sahista& obj2);
	friend bool operator <(const Sahista& obj1, const Sahista& obj2);
	friend bool operator == (const Sahista& obj1, const Sahista& obj2);
	friend bool operator != (const Sahista& obj1, const Sahista& obj2);
};

//Z4.9
ostream& operator << (ostream& COUT, const Sahista& s) {
	COUT << "Ime i prezime: " << s._imePrezime << endl;
	COUT << "Datum rodjenja: " << s._datumRodjenja << endl;
	COUT << "Drzava: " << s._drzava << endl;
	COUT << "Spol: " << ((*s._spol) ? "Muski" : "Zenski") << endl;
	return COUT;
}

//Z4.10 :: Odgovara na pitanje: "Da li je prvi sahista mladji od drugog?"
bool operator >(const Sahista& obj1, const Sahista& obj2) {
	return obj1.GetDatumRodjenja() > obj2.GetDatumRodjenja();
}

//Z4.11 :: Odgovara na pitanje: "Da li je drugi sahista mladji od prvog?"
bool operator <(const Sahista& obj1, const Sahista& obj2) {
	return obj1.GetDatumRodjenja() < obj2.GetDatumRodjenja();
}

//Vraca true ako sahisti imaju isto ime i prezime
bool operator == (const Sahista& obj1, const Sahista& obj2) {
	return strcmp(obj1._imePrezime, obj2._imePrezime) == 0;
}

bool operator != (const Sahista& obj1, const Sahista& obj2) {
	return strcmp(obj1._imePrezime, obj2._imePrezime) != 0;
}

//Z4.12 :: Koristiti genericku funkciju Max
Sahista* VratiNajmladjegSahistu(DinamickaKolekcija<Sahista>& sahisti) {
	Sahista* temp = &sahisti[0];
	for (int i = 1; i < sahisti.GetTrenutno(); i++)
	{
		if (Max<Sahista>(*temp,sahisti[i]) == *temp)
			temp = &sahisti[i];
	}
	return temp;
}