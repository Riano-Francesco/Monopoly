#include "Header/Spieler.h"

void Spieler::playerErstellen() {   
    cout << "Bitte Vornamen eingeben: ";
    cin >> playerName; // im Objekt definiert und kann genutzt werden - wird in sp hinterlegt.
    this->geld = 10000;
    this->position = 0;
    cout << "Spieler wurde hinzugefuegt.\n\n";
    
}

int Spieler::wuerfeln() {
    int wuerfeln1;
    int wuerfeln2;

    wuerfeln1 = rand() % 6 + 1;							// pseudo Algorithmus Zahl zwischen 1 & 6
    wuerfeln2 = rand() % 6 + 1;

    cout << "Erster Wuerfel: " << wuerfeln1 << endl;
    cout << "Zweiter Wuerfel: " << wuerfeln2 << endl;
    cout << "Schritte vorgehen: " << wuerfeln1 + wuerfeln2 << endl << endl;

    return wuerfeln1 + wuerfeln2;
}

void Spieler::getBesitzer() {
}

void Spieler::kaufen(Karte *feld) {
    feld->besitzer = this->playerName;
    this->geld -= feld->preis;   // Das Objekt welches die Funktion aufruft. Spieler ruft Kaufen auf
}

void Spieler::bezahlen(Karte *Miete, Spieler *besitzer) {

}

Spieler::Spieler() = default;
Spieler::~Spieler() = default;