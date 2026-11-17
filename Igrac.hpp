#ifndef IGRAC
#define IGRAC

#include <string>
#include <QObject>

enum class BojeIgraca{
    CRVENA,
    ZUTA,
    PLAVA,
    ZELENA,
    ROZE,
    LJUBICASTA
};

class Igrac : public QObject{

    Q_OBJECT

protected:
    int id;
    std::string ime;   //mora da bude player0-5
    BojeIgraca boja;
    int budzet;
 
public:
    Igrac(int id, const std::string& ime, BojeIgraca boja, int budzet, QObject* parent = nullptr);

    BojeIgraca getBoja() const;
    int getID() const;
    std::string getIme() const;
    int getBudzet() const;

    void dodajNaBudzet(int zarada);
};

#endif