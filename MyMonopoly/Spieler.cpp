#include "Spieler.h"

void Spieler::playerErstellen() {   
    cout << "Bitte Vornamen eingeben: ";
    cin >> playerName; // im Objekt definiert und kann genutzt werden - wird in sp hinterlegt.
    this->geld = 10000;
    this->position = 0;
    cout << "Spieler wurde hinzugef�gt.\n\n";
    
}

int Spieler::w�rfeln() {
    int w�rfeln1;
    int w�rfeln2;

    w�rfeln1 = rand() % 6 + 1;							// pseudo Algorythmus Zahl zwischen 1 & 6					
    w�rfeln2 = rand() % 6 + 1;

    cout << "Erster W�rfel: " << w�rfeln1 << endl;
    cout << "Zweiter W�rfel: " << w�rfeln2 << endl;
    cout << "Schritte vorgehen: " << w�rfeln1 + w�rfeln2 << endl << endl;

    return w�rfeln1 + w�rfeln2;
}

void Spieler::getBesitzer() {
}

void Spieler::kaufen(string spieler, string sname, int preis, int geld) {
    
}

Spieler::Spieler() {

}
Spieler::~Spieler() {
}