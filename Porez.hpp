#ifndef POREZ
#define POREZ

#include "Polje.hpp"

class Porez : public Polje{

private:
    int cena_poreza;

public:
    Porez(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int cena_poreza);
    int getCenaPoreza() const;
};

#endif