#include "Odmor.hpp"

Odmor::Odmor(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int br_krugova)
    : Polje(indeks, kategorija, naziv, putanjaSlike), br_krugova(br_krugova)
{
}

int Odmor::getBrojKrugova() const
{
    return br_krugova;
}
