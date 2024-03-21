#pragma once
#include "Karte.h"
#include <string>
#include <iostream>
using namespace std;

class Spieler {
public:
    Spieler();
    ~Spieler();

    string playerName;
    int geld;
    int position;

    void playerErstellen();
    int würfeln();
    void getBesitzer();
    void kaufen(Karte*, Spieler*);
};