#include "Igra.hpp"
#include <QCoreApplication>

Igra::Igra(Tabla* tabla, const QList<Igrac*>& igraci, QObject* parent)
    : QObject(parent), m_tabla(tabla), m_igraci(igraci)
{
    /*BUG FIX THIS!!!!!!*/
    //m_tabla->setParent(this);
    //for (Igrac* i : m_igraci)
    //    i->setParent(this);
}

Igra& Igra::getInstance(Tabla* tabla, const QList<Igrac*>& igraci)
{
    if (!s_instance) {
        Q_ASSERT_X(tabla, "Igra::getInstance", "prvi poziv mora da prosledi Tablu");
        s_instance = new Igra(tabla, igraci, QCoreApplication::instance());
    }
    return *s_instance;
}

Igrac* Igra::trenutniIgrac() const
{
    return m_igraci.isEmpty() ? nullptr : m_igraci[m_trenutni];
}