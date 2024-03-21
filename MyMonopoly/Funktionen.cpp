#include "Funktionen.h"
//#include "Spielfeld.h"
using namespace std;

bool abbruch = false;
bool wiederholung()
{
	cout << "Wiederholen ? 0 = Abbruch | 1 = Wiederholen" << endl;
	cin >> abbruch;

	return abbruch;
}

void startGame() {
	cout << "Willkommen bei Monopoly!\n";
	Spielfeld start;
	start.sAnzahl();
	start.Logik();
}


