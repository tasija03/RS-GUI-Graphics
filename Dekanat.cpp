#include "Dekanat.hpp"

Dekanat::Dekanat(int indeks, const std::string& kategorija, const std::string& naziv, const std::string& putanjaSlike, int br_krugova)
    : Polje(indeks, kategorija, naziv, putanjaSlike), br_krugova(br_krugova)
{
}

int Dekanat::getBrojKrugova() const
{
    return br_krugova;
}