#include "Spielfeld.h"
using namespace std;

void Spielfeld::sAnzahl() {

	int anzahl = 0;
	cout << "Bitte geben Sie die Anzahl der Spieler ein -> ";
	cin >> anzahl;

	if (anzahl > 8 || anzahl < 2) {
		cout << "Mindestens 2 - Maximal 8 Spieler!\n\n";
		cin >> anzahl;
	}
	else {
		for (int i = 0; i < anzahl; i++) {
			Spieler sp; // Aufruf des Objektes aufgrund des erstellten Konstruktors - bei mehreren mit Parametern arbeiten zum unterscheiden
			sp.playerErstellen();
			spieler.push_back(sp);
		}
		cout << "Insgesamt " << anzahl << " Spieler nehmen teil.\n";
	}
}

Spielfeld::Spielfeld() {
	ifstream streets("Straßennamen");
	ifstream price("Preise");

		for (int i = 0; i < 40; i++) {
			string lines;
			string lines2;hure

			
			getline(streets, lines);
			
			int preis = stoi(getline(price, lines2));

			felder[i].streetName = lines;
			felder[i].preis = lines2;
		}
	
	streets.close();
	price.close();
}
Spielfeld::~Spielfeld() {
}

