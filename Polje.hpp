#ifndef POLJE_HPP
#define POLJE_HPP

#include <QObject>
#include <QString>

class Polje : public QObject{
    Q_OBJECT
    Q_PROPERTY(int indeks READ getIndeks CONSTANT)
    Q_PROPERTY(QString kategorija READ getKategorija CONSTANT)
    Q_PROPERTY(QString naziv READ getNaziv CONSTANT)
    Q_PROPERTY(QString putanjaSlike READ getPutanjaSlike CONSTANT)

protected:
    int indeks;
    QString kategorija;
    QString naziv;
    QString putanjaSlike;

public:
    Polje(int indeks,
          const QString& kategorija,
          const QString& naziv,
          const QString& putanjaSlike,
          QObject* parent = nullptr);


    virtual ~Polje() = default;

    int getIndeks() const;
    QString getKategorija() const;
    QString getNaziv() const;
    QString getPutanjaSlike() const;

};

#endif