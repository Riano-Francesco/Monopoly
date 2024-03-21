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
		cout << "Insgesamt " << anzahl << " Spieler nehmen teil.\n\n";
	}
}

Spielfeld::Spielfeld() {
	ifstream streets("Strassennamen");
	ifstream price("Preise");
	ifstream color("Farbe");
	ifstream rent("Miete");

		for (int i = 0; i < 40; i++) {
			string lines;
			string lines2;
			string lines3;
			string lines4;

			getline(streets, lines);

			getline(price, lines2);
			int preis = stoi(lines2);

			getline(color, lines3);

			getline(rent, lines4);
			int mieten = stoi(lines4);

			Spieler bank;
			bank.playerName = "Bank"; // Bank Spieler erstellt

			felder[i].streetName = lines;
			felder[i].preis = preis;
			felder[i].farbe = lines3;
			felder[i].Miete = mieten;
			felder[i].besitzer = bank;
		}

		//For : Each
		/*for (auto elem : felder) {
			cout << elem.streetName << " " << elem.preis << " " << elem.farbe << " " << elem.Miete << endl;
		}*/
	streets.close();
	price.close();
	color.close();
	rent.close();
}
Spielfeld::~Spielfeld() {
}

void Spielfeld::Logik() {
	/*int i = 0;
	if (i == spieler.size()) {
		i = 0;
	}*/
	do
	{
		for (int i = 0; i < spieler.size(); i++) {
			cout << spieler[i].playerName << " hat gewürfelt: " << endl;
			spieler[i].position += spieler[i].würfeln(); // Um die Position entsprechend der gewürfelten Summe zu verändern.
			spieler[i].position = spieler[i].position % 40; // Range von 0 - 39

			if (felder[spieler[i].position].besitzer.playerName == spieler[i].playerName) {
				cout << "Dieses Feld gehört dir." << endl;
			}
			else if (felder[spieler[i].position].besitzer.playerName == "Bank") {
				spieler[i].kaufen();
			}

		}

	} while (spieler.size() != 1);
}

