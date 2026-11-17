#include "Lokacija.hpp"

Lokacija::Lokacija(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int cena, int taksa_kupljeno)
    : PoljeZaKupovinu(indeks, kategorija, naziv, putanjaSlike, cena, taksa_kupljeno)
        {
           
        }

void Lokacija::akcija() {}