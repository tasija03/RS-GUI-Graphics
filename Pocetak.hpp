#ifndef POCETAK
#define POCETAK

#include "Polje.hpp"

class Pocetak : public Polje{

private:
    int dodatak;

public:
    Pocetak(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int dodatak);
    int getDodatak() const;
};

#endif