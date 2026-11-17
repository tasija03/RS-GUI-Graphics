#include "PoljeZaKupovinu.hpp"

PoljeZaKupovinu::PoljeZaKupovinu(int indeks, const QString& kategorija, const QString& naziv,
                                 const QString& putanjaSlike, int cena, int taksa_kupljeno,
                                 QObject* parent)
    : Polje(indeks, kategorija, naziv, putanjaSlike, parent),
    cena(cena), taksa_kupljeno(taksa_kupljeno), vlasnik(nullptr)
{
}

int PoljeZaKupovinu::getCena() const { return cena; }
Igrac* PoljeZaKupovinu::getVlasnik() const { return vlasnik; }
int PoljeZaKupovinu::getTaksaKupljeno() const { return taksa_kupljeno; }

void PoljeZaKupovinu::setVlasnik(Igrac* novi_vlasnik) { vlasnik=novi_vlasnik; }
