#include "Igrac.hpp"

Igrac::Igrac(int id, const std::string& ime, BojeIgraca boja, int budzet, QObject* parent) : QObject (parent), id(id), ime(ime), boja(boja), budzet(budzet)
{
}

BojeIgraca Igrac::getBoja() const { return boja; }
int Igrac::getID() const { return id; }
std::string Igrac::getIme() const { return ime; }
int Igrac::getBudzet() const { return budzet; }

void Igrac::dodajNaBudzet(int dodatak)
{
    budzet+=dodatak;
}