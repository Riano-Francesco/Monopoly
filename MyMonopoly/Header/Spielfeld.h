#pragma once
#include <iostream>
#include <locale>  // Passt UTF an Sprache des Systems an
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>     // f�r srand und rand
#include <ctime>		// f�r time(NULL) = Zeit vom aktuellen System
#include "Karte.h"

#include "Spieler.h"

using namespace std;

class Spielfeld {
public:
	Spielfeld();
	~Spielfeld();

	void Logik();

	Karte felder[40];
	vector<Spieler> spieler;

	void sAnzahl();
};