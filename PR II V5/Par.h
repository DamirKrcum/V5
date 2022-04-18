#pragma once
#include <iostream>
#include <memory>
#include"Funkcije.h"
using namespace std;

template<class T1, class T2>
class Par {
	T1 _lijevi;
	T2 _desni;
public:
	//Z5.1
	Par() {

	}
	Par(T1 el1, T2 el2) {
		_lijevi = el1;
		_desni = el2;
	}
	//Z5.2
	Par(const Par<T1, T2>& obj)
		:_lijevi(obj._lijevi), _desni(obj._desni)
	{
	}
	Par(Par<T1, T2>&& obj) 
		:_lijevi(move(obj._lijevi)), _desni(move(obj._desni))
	{
		
	}

	//Z5.3
	Par<T1, T2>& operator = (const Par<T1, T2>& obj) {
		if (this == &obj)
			return *this;
		_lijevi = obj._lijevi;
		_desni = obj._desni;
		return *this;
	}
	//Z5.4
	T1 GetLijevi() const { return _lijevi; }
	T2 GetDesni() const { return _desni; }
};

//Z5.5
template<class T1, class T2>
ostream& operator << (ostream& COUT, const Par<T1, T2>& par){
	COUT << "|" << par._lijevi << " - " << par._desni << "|";
	return COUT;
}