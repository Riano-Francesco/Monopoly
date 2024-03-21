#include "Spieler.h"

void Spieler::playerErstellen() {   
    cout << "Bitte Vornamen eingeben: ";
    cin >> playerName; // im Objekt definiert und kann genutzt werden - wird in sp hinterlegt.
    this->geld = 10000;
    this->position = 0;
    cout << "Spieler wurde hinzugefügt.\n\n";
    
}

int Spieler::würfeln() {
    int würfeln1;
    int würfeln2;

    würfeln1 = rand() % 6 + 1;							// pseudo Algorythmus Zahl zwischen 1 & 6					
    würfeln2 = rand() % 6 + 1;

    cout << "Erster Würfel: " << würfeln1 << endl;
    cout << "Zweiter Würfel: " << würfeln2 << endl;
    cout << "Schritte vorgehen: " << würfeln1 + würfeln2 << endl << endl;

    return würfeln1 + würfeln2;
}

void Spieler::getBesitzer() {
}

void Spieler::kaufen(string spieler, string sname, int preis, int geld) {
    
}

Spieler::Spieler() {

}
Spieler::~Spieler() {
}