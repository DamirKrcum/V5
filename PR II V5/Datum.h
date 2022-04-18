#pragma once
#include <iostream>
#include <memory>
using namespace std;


class Datum
{
private:
	shared_ptr<int> _dan;
	shared_ptr<int> _mjesec;
	shared_ptr<int> _godina;
public:
	//Z1.1
	Datum() {

	}
	void dealociraj() 
	{
		_dan.reset();
		_mjesec.reset();
		_godina.reset();
	}
	//Z1.2
	Datum(int dan, int mjesec, int godina)
	{
		_dan = make_shared<int>(dan);
		_mjesec = make_shared<int>(mjesec);
		_godina = make_shared<int>(godina);
	}

	//Z1.3
	Datum(const Datum& obj) {
		_dan = make_shared<int>(*obj._dan);
		_mjesec = make_shared<int>(*obj._mjesec);
		_godina = make_shared<int>(*obj._godina);
	}

	//Z1.4
	Datum(Datum&& obj) {
		_dan = obj._dan;
		obj._dan = nullptr;
		_mjesec = obj._mjesec;
		obj._mjesec = nullptr;
		_godina = obj._godina;
		obj._godina = nullptr;
	}

	//Z1.5
	Datum& operator =(const Datum& obj) {
		if (this == &obj)
			return *this;
		dealociraj();
		_dan = make_shared<int>(*obj._dan);
		_mjesec = make_shared<int>(*obj._mjesec);
		_godina = make_shared<int>(*obj._godina);
		return *this;
	}

	//Z1.6
	void SetDan(int dan) {
		if (_dan == nullptr)
			_dan = make_shared<int>();
		*_dan = dan;
	}
	void SetMjesec(int mjesec) {
		if (_mjesec == nullptr)
			_mjesec = make_shared<int>();
		*_mjesec = mjesec;
	}
	void SetGodina(int godina) {
		if (_godina == nullptr)
			_godina = make_shared<int>();
		*_godina = godina;
	}


	int GetDan() const { return *_dan; }
	int GetMjesec() const { return *_mjesec; }
	int GetGodina() const { return *_godina; }
	//Z1.7
	~Datum() {
		dealociraj();
	}

	friend ostream& operator << (ostream& COUT, const Datum& datum);
	friend bool operator == (const Datum& d1, const Datum& d2);
	friend bool operator > (const Datum&, const Datum&);
	
	
};
int dateToInt(Datum d) {
	return d.GetGodina() * 365 + d.GetMjesec() * 30 + d.GetDan();
}


//Z1.8
bool operator == (const Datum& d1, const Datum& d2) {
	return *d1._godina == *d2._godina && *d1._mjesec == *d2._mjesec && *d1._dan == *d2._dan;
}
//Z1.9
bool operator > (const Datum& d1, const Datum& d2) {
	return dateToInt(d1) > dateToInt(d2);
}
bool operator >= (const Datum& d1, const Datum& d2) {
	return (d1 > d2) || (d1 == d2);
}
bool operator < (const Datum& d1, const Datum& d2) {
	return !(d1 >= d2);
}
bool operator <= (const Datum& d1, const Datum& d2) {
	return !(d1 > d2);
}
//Z1.10
ostream& operator << (ostream& COUT, const Datum& datum) {
	COUT << *datum._dan << "." << *datum._mjesec << "." << *datum._godina;
	return COUT;
}
