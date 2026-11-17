#include "Predmet.hpp"

Predmet::Predmet(int indeks, const QString& kategorija, const QString& naziv,
                 const QString& putanjaSlike, int cena, int taksa_kupljeno,
                 const QString& boja, const std::vector<int>& takse, int hipoteka,
                 QObject* parent)
    : PoljeZaKupovinu(indeks, kategorija, naziv, putanjaSlike, cena, taksa_kupljeno, parent),
    boja(boja), hipoteka(hipoteka)
{
    IzvuciTakse();
}

void Predmet::IzvuciTakse()
{
    if (takse.size()==4)
    {
        taksa_predispitne=takse[0];
        taksa_pismeni=takse[1];
        taksa_projekat=takse[2];
        taksa_usmeni=takse[3];
    }
}


QString Predmet::getBoja() const { return boja; }
int Predmet::getTaksaPredispitne() const { return taksa_predispitne; }
int Predmet::getTaksaPismeni() const { return taksa_pismeni; }
int Predmet::getTaksaProjekat() const { return taksa_projekat; }
int Predmet::getTaksaUsmeni() const { return taksa_usmeni; }

void Predmet::akcija(){}