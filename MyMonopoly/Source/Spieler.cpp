#include "Header/Spieler.h"

void Spieler::playerErstellen() {   
    cout << "Bitte Vornamen eingeben: ";
    cin >> playerName; // im Objekt definiert und kann genutzt werden - wird in sp hinterlegt.
    this->geld = 5000;
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
    cout << "Schritte vorgehen: " << wuerfeln1 + wuerfeln2 << endl;

    return wuerfeln1 + wuerfeln2;
}

int Spieler::getBesitzer(Karte *feld, vector < Spieler > *spieler) { // * <- um mit Original zu arbeiten
    for (int i = 0; i < spieler->size(); i++) { // size() bei Vector
        if (spieler->at(i).playerName == feld->besitzer) {
            return i;
        }
    }
    return 0;
}

void Spieler::kaufen(Karte *feld) {
    feld->besitzer = this->playerName;
    this->geld -= feld->preis;   // Das Objekt welches die Funktion aufruft. Spieler ruft Kaufen auf
    cout << "Spieler " << this->playerName << " hat das Feld " << feld->streetName << " gekauft.\n";
}

void Spieler::bezahlen(Karte *feld, Spieler *besitzer) {
    this->geld -= feld->Miete;
    besitzer->geld += feld->Miete;
    cout << "Spieler " << this->playerName << " hat " << feld->Miete << " an " << besitzer->playerName << " bezahlt.\n";
}

void Spieler::verkaufen(Karte *felder) {
    while (this->geld < felder->Miete) {
        int lowprice = 50000;
        int index = 0;
        for (int i = 0; i < 40; i++) {
            if (this->playerName == felder[i].besitzer) {
                if (felder[i].preis < lowprice) {
                    lowprice = felder[i].preis;
                    index = i;
                }
            } else {
                cout << this->playerName << " ist Pleite. Sie haben Verloren." << endl;
                this->gameOver = true;
                return;
            }
        }
        felder[index].besitzer = "Bank";
        this->geld += felder[index].preis;
        cout << "Spieler " << this->playerName << " hat das Feld " << felder[index].streetName << " fuer " << felder[index].preis << " verkauft.\n";
    }
}

Spieler::Spieler() = default;
Spieler::~Spieler() = default;