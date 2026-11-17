#pragma once
#include <QObject>
#include <QQmlListProperty>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "Polje.hpp"

class Tabla : public QObject {
    Q_OBJECT
    // Izlažemo 4 liste QML-u
    Q_PROPERTY(QQmlListProperty<Polje> bottomFields READ bottomFields CONSTANT)
    Q_PROPERTY(QQmlListProperty<Polje> leftFields READ leftFields CONSTANT)
    Q_PROPERTY(QQmlListProperty<Polje> topFields READ topFields CONSTANT)
    Q_PROPERTY(QQmlListProperty<Polje> rightFields READ rightFields CONSTANT)

private:
    QList<Polje*> m_bottomFields;
    QList<Polje*> m_leftFields;
    QList<Polje*> m_topFields;
    QList<Polje*> m_rightFields;

public:
    explicit Tabla(QObject *parent = nullptr);

    QQmlListProperty<Polje> bottomFields();
    QQmlListProperty<Polje> leftFields();
    QQmlListProperty<Polje> topFields();
    QQmlListProperty<Polje> rightFields();
    void ucitajKarticeIzJsona(const QString &filePath);

signals:
    void bottomFieldsChanged();
    void leftFieldsChanged();
    void topFieldsChanged();
    void rightFieldsChanged();
};
