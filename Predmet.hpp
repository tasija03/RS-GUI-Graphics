#ifndef PREDMET
#define PREDMET

#include <QString>
#include <vector>
#include "PoljeZaKupovinu.hpp"


class Predmet : public PoljeZaKupovinu{

protected:
    QString boja;
    std::vector<int> takse;
    int taksa_predispitne;
    int taksa_pismeni;
    int taksa_projekat;
    int taksa_usmeni;
    int hipoteka;

public:
    Predmet(int indeks, const QString& kategorija, const QString& naziv,
            const QString& putanjaSlike, int cena, int taksa_kupljeno,
            const QString& boja, const std::vector<int>& takse, int hipoteka,
            QObject* parent = nullptr);

    void akcija() override;

    QString getBoja() const;
    int getTaksaPredispitne() const;
    int getTaksaPismeni() const;
    int getTaksaProjekat() const;
    int getTaksaUsmeni() const;

private:
    void IzvuciTakse();


};

#endif