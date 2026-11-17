#include "Pocetak.hpp"

Pocetak::Pocetak(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int dodatak)
    : Polje(indeks, kategorija, naziv, putanjaSlike), dodatak(dodatak)
{
}

int Pocetak::getDodatak() const
{
    return dodatak;
}

