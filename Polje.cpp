#include "Polje.hpp"

Polje::Polje(int indeks,
             const QString& kategorija,
             const QString& naziv,
             const QString& putanjaSlike,
             QObject* parent)
    : QObject(parent),
    indeks(indeks),
    kategorija(kategorija),
    naziv(naziv),
    putanjaSlike(putanjaSlike)
{
}



int Polje::getIndeks() const { return indeks; }
QString Polje::getKategorija() const { return kategorija; }
QString Polje::getNaziv() const { return naziv; }
QString Polje::getPutanjaSlike() const { return putanjaSlike; }
