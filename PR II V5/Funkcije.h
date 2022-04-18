#pragma once
#include <iostream>
#include <memory>
#include"Datum.h"
using namespace std;
//Z0.1
char* AlocirajIKopiraj(const char* izvor) {
    if (izvor == nullptr)
        return nullptr;
    int vel = strlen(izvor) + 1;
    char* temp = new char[vel];
    strcpy_s(temp, vel, izvor);
    return temp;
}

//Z0.2 :: Funkcija vraca max. od dva elementa
template<typename T>
T Max(T el1, T el2) {
    return (el1 > el2) ? el1 : el2;
}

//Z0.3 :: Funkcija vraca min. od dva elementa
template<typename T>
T Min(T el1, T el2) {
    return (el1 < el2) ? el1 : el2;
}
