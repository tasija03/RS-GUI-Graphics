#ifndef POLJE_KUPOVINA
#define POLJE_KUPOVINA

#include "Polje.hpp"
#include "Igrac.hpp"

class PoljeZaKupovinu : public Polje{

protected:
    int cena;
    int taksa_kupljeno;
    Igrac* vlasnik;

public:
    PoljeZaKupovinu(int indeks, const QString& kategorija, const QString& naziv,
                    const QString& putanjaSlike, int cena, int taksa_kupljeno,
                    QObject* parent = nullptr);

    int getCena() const;
    Igrac* getVlasnik() const;
    int getTaksaKupljeno() const;

    void setVlasnik(Igrac* novi_vlasnik);

    virtual void akcija() = 0;
};

#endif