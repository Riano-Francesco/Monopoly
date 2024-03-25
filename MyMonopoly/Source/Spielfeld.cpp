#include "Header/Spielfeld.h"
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
			Spieler sp; // Aufruf des Objektes aufgrund des erstellten Konstruktors - bei mehreren mit Parametern arbeiten zum Unterscheiden
			sp.playerErstellen(); // Methodenaufruf
			spieler.push_back(sp);
		}
		cout << "Insgesamt " << anzahl << " Spieler nehmen teil.\n\n";
	}
}

Spielfeld::Spielfeld() {
	ifstream streets("../Strassennamen.txt");
	ifstream price("../Preise.txt");
	ifstream color("../Farbe.txt");
	ifstream rent("../Miete.txt");

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


			string bank = "Bank"; // Bank Spieler erstellt

            felder[i] = Karte(lines, preis, lines3, mieten, bank); // Inhalt der TXT in Array speichern
		}

		//For : Each
		/*for (auto elem : felder) {
			cout << elem.streetName << " " << elem.preis << " " << elem.farbe << " " << elem.Miete.txt << endl;
		}*/
	streets.close();
	price.close();
	color.close();
	rent.close();
}
Spielfeld::~Spielfeld() = default;

void Spielfeld::Logik() {

    int rounds = 0;
	do
	{
		for (int i = 0; i < spieler.size(); i++) {
            cout << endl;
            if (spieler[i].gameOver) {
                continue;
            }

            int plAnz = 0;
            int gewinner = 0;
            for (int i = 0; i < spieler.size(); i++) {
                if (!spieler[i].gameOver) {
                    plAnz++;
                    gewinner = i;
                }
            }
            if (plAnz == 1) {
                cout << spieler[gewinner].playerName <<" hat gewonnen.";
                return;
            }

			cout << spieler[i].playerName << " hat gewuerfelt: " << endl;
			spieler[i].position += spieler[i].wuerfeln(); // Um die Position entsprechend der gewürfelten Summe zu verändern.
//			spieler[i].position = spieler[i].position % 40; // Range von 0 bis 39
            if (spieler[i].position > 39) { // Selbsterklärend für LOS
                spieler[i].position -= 40;
                spieler[i].geld += 200;
                cout << "Sie sind über LOS gegangen und haben 200 erhalten." << endl;
            }

			if (felder[spieler[i].position].besitzer == spieler[i].playerName) { // Abfrage, ob aktuelle Position mir gehört
				cout << "Dieses Feld gehoert " << spieler[spieler[i].getBesitzer(&felder[spieler[i].position], &spieler)].playerName << endl;
			}
			else if (felder[spieler[i].position].besitzer == "Bank") { // Abfrage, ob Besitzer Bank ist
                if (felder[spieler[i].position].preis == 0){ // Um Ereignis-, Gemeinschaftsfelder etc. zu überspringen
                    continue;
                }
				spieler[i].kaufen(&felder[spieler[i].position]); // Wenn Bank besitzer ist kann Spieler feld kaufen -> Methodenaufruf
                //  cout << felder[spieler[i].position].besitzer << endl; // Ausgabe Besitzer
			} else {
                int tempbesitzer = spieler[i].getBesitzer(&felder[spieler[i].position], &spieler); // Zum Zwischenspeichern des Besitzers
                if (spieler[i].geld < felder[spieler[i].position].Miete) { // Abfrage wenn Miete nicht bezahlbar ist
                    cout << "Sie haben nicht genug Geld. Bitte verkaufen Sie Strassen bis Sie genug Geld haben!" << endl;
                    bool kannbezahlen = spieler[i].verkaufen(this->felder); // Methodenaufruf zum Straßenverkauf wenn Geld für Miete nicht ausreicht
                    if(!kannbezahlen) {
                        cout << spieler[i].playerName << " ist Pleite. Sie haben Verloren!" << endl; // Kann er nicht bezahlen ist er Pleite
                        spieler[i].gameOver = true;
                        continue;
                    } else {
                        spieler[i].bezahlen(&felder[spieler[i].position], &spieler[tempbesitzer]); // Kann er nach Verkauf bezahlen -> Methodenaufruf
                    }
                } else {
                    spieler[i].bezahlen(&felder[spieler[i].position], &spieler[tempbesitzer]); // Wenn er nicht verkaufen muss bezahlt er einfach Miete
                }
            }
            cout << endl;
		}
        rounds++;
        cout << "Runde " << rounds << " beendet." << endl;
	} while (spieler.size() != 1);
}

