#include "Karte.h"

Karte::Karte() {
}

Karte::Karte(string sname, string color, int kaufpreis, int miete) {

    this->streetName = sname;
    this->farbe = color;
    this->preis = kaufpreis;
    this->Miete = miete;
}
Karte::~Karte() {
}