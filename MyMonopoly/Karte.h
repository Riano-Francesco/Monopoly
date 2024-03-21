#pragma once
//#include "Spielfeld.h"
#include "Spieler.h"
#include <string>
#include <iostream>
using namespace std;

class Karte {
public:
    Karte();
    Karte(string sname, string farbe, int kaufpreis, int miete);
    ~Karte();
    string streetName;
    string farbe;
    int preis;
    int Miete;
    Spieler besitzer;
};