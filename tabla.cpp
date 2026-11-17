#include "tabla.h"
#include "Predmet.hpp"
#include "Polje.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Tabla::Tabla(QObject *parent) : QObject(parent) {
    // Proveri da li je putanja tačna (probaj sa ":/kartice.json" ako je u qrc resursima)
    ucitajKarticeIzJsona("./kartice.json");
}

QQmlListProperty<Polje> Tabla::bottomFields() {
    return QQmlListProperty<Polje>(this, &m_bottomFields);
}
QQmlListProperty<Polje> Tabla::leftFields() {
    return QQmlListProperty<Polje>(this, &m_leftFields);
}
QQmlListProperty<Polje> Tabla::topFields() {
    return QQmlListProperty<Polje>(this, &m_topFields);
}
QQmlListProperty<Polje> Tabla::rightFields() {
    return QQmlListProperty<Polje>(this, &m_rightFields);
}

void Tabla::ucitajKarticeIzJsona(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "GREŠKA: Ne mogu da otvorim fajl sa karticama na putanji:" << filePath;
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "GREŠKA: Neispravan JSON format!";
        return;
    }

    QJsonObject rootObj = doc.object();

    // Lambda funkcija za bezbedno parsiranje jedne strane table
    auto parseFields = [this](const QJsonArray &array, QList<Polje*> &fieldList) {
        fieldList.clear();
        for (const QJsonValue &val : array) {
            if (!val.isObject()) continue;
            QJsonObject obj = val.toObject();

            QString kategorija = obj["kategorija"].toString("nepoznato");

            if (kategorija == "predmet") {
                int indeks = obj["indeks"].toInt(0);
                QString naziv = obj["naziv"].toString("");
                QString boja = obj["boja"].toString("#ffffff");
                int cena = obj["cena"].toInt(0);
                QString putanjaSlike = obj["putanjaSlike"].toString("");
                int taksa_kupljeno = obj["taksa_kupljeno"].toInt(0);
                int taksaPredispitne = obj["taksa_predispitne"].toInt(0);
                int taksaPismeni = obj["taksa_pismeni"].toInt(0);
                int taksaProjekat = obj["taksa_projekat"].toInt(0);
                int taksaUsmeni = obj["taksa_usmeni"].toInt(0);
                int hipoteka = obj["hipoteka"].toInt(0);

                fieldList.append(new Predmet(indeks, kategorija, naziv, putanjaSlike, cena,
                                             taksa_kupljeno, boja,
                                             {taksaPredispitne, taksaPismeni, taksaProjekat, taksaUsmeni},
                                             hipoteka, this));
            }
        }
    };

    parseFields(rootObj["bottomFields"].toArray(), m_bottomFields);
    parseFields(rootObj["leftFields"].toArray(), m_leftFields);
    parseFields(rootObj["topFields"].toArray(), m_topFields);
    parseFields(rootObj["rightFields"].toArray(), m_rightFields);

    qDebug() << "Uspešno učitano polja -> Bottom:" << m_bottomFields.size()
             << "Left:" << m_leftFields.size()
             << "Top:" << m_topFields.size()
             << "Right:" << m_rightFields.size();

    emit bottomFieldsChanged();
    emit leftFieldsChanged();
    emit topFieldsChanged();
    emit rightFieldsChanged();
}