#ifndef DEKANAT
#define DEKANAT

#include "Polje.hpp"

class Dekanat : public Polje{

private:
    int br_krugova; //broj krugova koliko neko treba da je u kazni

public:
    Dekanat(int indeks, const std::string& kategorija, const std::string& naziv, const std::string& putanjaSlike, int br_krugova);
    int getBrojKrugova() const;
};

#endif