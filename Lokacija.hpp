#ifndef LOKACIJA
#define LOKACIJA

#include "PoljeZaKupovinu.hpp"

class Lokacija : public PoljeZaKupovinu{

protected:
 
public:
    Lokacija(int indeks, const QString& kategorija, const QString& naziv, const QString& putanjaSlike, int cena, int taksa_kupljeno);
    
    void akcija() override;

};

#endif