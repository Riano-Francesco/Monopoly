#include "Header/Karte.h"

Karte::Karte() = default;
Karte::Karte(string sname, int kaufpreis, string color, int miete, string bank) {

    this->streetName = sname;
    this->farbe = color;
    this->preis = kaufpreis;
    this->Miete = miete;
    this->besitzer = bank;
}
Karte::~Karte() = default;