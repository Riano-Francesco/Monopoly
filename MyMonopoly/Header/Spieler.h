#pragma once
#include "Karte.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Spieler {
public:
    Spieler();
    ~Spieler();

    string playerName;
    int geld{};
    int position{};
    bool gameOver = false;

    void playerErstellen();
    int wuerfeln();
    int getBesitzer(Karte *feld, vector < Spieler > *spieler);
    void kaufen(Karte *feld);
    bool verkaufen(Karte *feld);
    void bezahlen(Karte *feld, Spieler *besitzer);
};