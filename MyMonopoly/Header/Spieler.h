#pragma once
#include <string>
#include "Karte.h"
#include <iostream>
using namespace std;

class Spieler {
public:
    Spieler();
    ~Spieler();

    string playerName;
    int geld{};
    int position{};

    void playerErstellen();
    int wuerfeln();
    void getBesitzer();
    void kaufen(Karte *feld);
    void bezahlen(Karte *Miete, Spieler *besitzer);
};