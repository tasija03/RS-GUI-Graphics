#include "Porez.hpp"

Porez::Porez(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int cena_poreza)
    : Polje(indeks, kategorija, naziv, putanjaSlike), cena_poreza(cena_poreza)
{
}

int Porez::getCenaPoreza() const
{
    return cena_poreza;
}
