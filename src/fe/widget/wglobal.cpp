#include "wglobal.h"

QString WGlobal::fromUtente(const Utente *u) {
    QString str(QString::fromStdString(
                    u->getUsername() + ", " +
                    u->getNome() + ", " +
                    u->getCognome() + ", grado"));
    str.append(QString::number(u->getGrado()));
    const UtenteAvanzato* punt(dynamic_cast <const UtenteAvanzato*> (u));
    if (punt) {
        str.append(", card number:");
        str.append(QString::number(punt->getCardNumber()));
    } // if
    return str;
} // fromUtente

QString WGlobal::fromBook(const Libro *l) {
    QString str(QString::fromStdString(l->getTitolo() + ", " + l->getAutore() + ", " + l->getCasaEditrice() + ", " + l->getGenere() + ", anno:"));
    str.append(QString::number(l->getAnno()));
    str.append("; grado:");
    str.append(QString::number(l->getGrado()));
    str.append(": ncopie:");
    str.append(QString::number(l->size()));
    return str;
} // fromLibro

#ifdef Q_OS_LINUX
const unsigned int WGlobal::MIN_BOX = 0;
#else // per la risoluzione
const unsigned int WGlobal::MIN_BOX = 500;
#endif
