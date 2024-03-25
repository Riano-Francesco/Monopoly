#pragma once
//#include "Spielfeld.h"
#include <string>
#include <iostream>
using namespace std;

class Karte {
public:
    Karte();
    Karte(string sname, int kaufpreis, string farbe, int miete, string bank);
    ~Karte();

    string streetName;
    string farbe;

    int preis{};
    int Miete{};

    string besitzer;
};