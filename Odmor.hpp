#ifndef ODMOR
#define ODMOR

#include "Polje.hpp"

class Odmor : public Polje{

private:
    int br_krugova; //broj krugova koliko neko treba da odmara

public:
    Odmor(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int br_krugova);
    int getBrojKrugova() const;
};

#endif