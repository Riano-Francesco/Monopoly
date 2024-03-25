#include "Header/Spieler.h"

void Spieler::playerErstellen() {   
    cout << "Bitte Vornamen eingeben: ";
    cin >> playerName; // im Objekt definiert und kann genutzt werden - wird in sp hinterlegt.
    this->geld = 1500; // Festsetzung Startgeld pro Spieler
    this->position = 0; // Startposition LOS
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
        if (spieler->at(i).playerName == feld->besitzer) { // Abfrage um den Besitzer des Feldes zu bekommen
            return i;
        }
    }
    return 0;
}

void Spieler::kaufen(Karte *feld) {
    feld->besitzer = this->playerName; // Felt wird in Besitzer hinterlegt und an entsprechenden Spieler übergeben
    this->geld -= feld->preis;   // Das Objekt welches die Funktion aufruft. Spieler ruft Kaufen auf -> Geld wird entsprechend Preis weniger
    cout << "Spieler " << this->playerName << " hat das Feld " << feld->streetName << " gekauft.\n";
}

void Spieler::bezahlen(Karte *feld, Spieler *besitzer) {
    this->geld -= feld->Miete; // Geld wird entsprechend Miete weniger
    besitzer->geld += feld->Miete; // Der Miete erhält erhöht entsprechend gezahlter Summe Geld
    cout << "Spieler " << this->playerName << " hat " << feld->Miete << " an " << besitzer->playerName << " bezahlt.\n";
}

bool Spieler::verkaufen(Karte *feld) {
    while (this->geld < feld->Miete) { // Überprüfung ob Geld für Miete reicht
        int lowprice = 50000;
        int index = 0;
        for (int i = 0; i < 40; i++) { // Um alle Felder durchzugehen um zu schauen, welche Straßen dem Spieler gehören
            if (this->playerName == feld[i].besitzer) { // Dieser Spieler besitzt welche Straßen
                if (feld[i].preis < lowprice) {
                    lowprice = feld[i].preis; // Vorgang mit zwischenspeicherung um die Straßen zu verkaufen
                    index = i;
                }
            } else {
                return false;
            }
        }
        feld[index].besitzer = "Bank"; // Besitzer des verkauften Feldes wird wieder Bank und ist somit wieder kaufbar
        this->geld += feld[index].preis; // Geld erhöht sich um den Verkaufspreis der verkauften Straße
        cout << "Spieler " << this->playerName << " hat das Feld " << feld[index].streetName << " fuer " << feld[index].preis << " verkauft.\n";
    }
    return true;
}

Spieler::Spieler() = default;
Spieler::~Spieler() = default;