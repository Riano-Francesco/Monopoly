#include <iostream>
#include <locale> 
#include "Funktionen.h"

using namespace std;

int main() {
	locale::global(locale(""));		// für Umlaute
	bool abbruch;
	do {
		srand(time(NULL));			    					// Random seed = pseudo Algorythmus für zufällige generation einer Zahl

		startGame();

		cout << endl;
		cout << endl;
		cout << endl;
		abbruch = wiederholung();
		system("CLS");
	} while (abbruch);
	return  0;
}