#ifndef IGRA_HPP
#define IGRA_HPP

#include <QObject>
#include <QList>
#include "tabla.h"
#include "Igrac.hpp"

class Igra : public QObject {
    Q_OBJECT
    Q_PROPERTY(Tabla* tabla READ tabla CONSTANT)
    Q_PROPERTY(Igrac* trenutniIgrac READ trenutniIgrac)

public:
    Igra(const Igra&) = delete;
    Igra& operator=(const Igra&) = delete;

    // Prvi poziv pravi instancu (mora dobiti Tablu i igrače), svaki sledeći je samo vraća
    static Igra& getInstance(Tabla* tabla = nullptr,
                             const QList<Igrac*>& igraci = {});

    Tabla* tabla() const { return m_tabla; }
    Igrac* trenutniIgrac() const;

private:
    Igra(Tabla* tabla, const QList<Igrac*>& igraci, QObject* parent);

    static inline Igra* s_instance = nullptr;

    Tabla* m_tabla;
    QList<Igrac*> m_igraci;
    int m_trenutni = 0;
};

#endif // IGRA_HPP