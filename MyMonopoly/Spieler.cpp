#include "Spieler.h"

void Spieler::playerErstellen() {   
    cout << "Bitte Vornamen eingeben: ";
    cin >> playerName; // im Objekt definiert und kann genutzt werden - wird in sp hinterlegt.
    this->geld = 50000;
    this->position = 0;
    cout << "Spieler wurde hinzugefügt.\n\n";

}

int Spieler::würfeln() {
    int würfeln1;
    int würfeln2;

    srand(time(NULL));									// Random seed = pseudo Algorythmus für zufällige generation einer Zahl
    würfeln1 = rand() % 6 + 1;							// pseudo Algorythmus Zahl zwischen 1 & 6

    srand(time(NULL));									// Random seed = pseudo Algorythmus für zufällige generation einer Zahl
    würfeln2 = rand() % 6 + 1;

    cout << "Erster Würfel: " << würfeln1 << endl;
    cout << "Zweiter Würfel: " << würfeln2 << endl;
    cout << "Schritte vorgehen: " << würfeln1 + würfeln2;
    return 1;
}

void Spieler::getBesitzer()
{
}

void Spieler::kaufen()
{
}

Spieler::Spieler() {

}
Spieler::~Spieler() {
}