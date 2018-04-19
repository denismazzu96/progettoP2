// fe/widget/wglobal.h

#ifndef WGLOBAL_H
#define WGLOBAL_H

// Qt
#include <QString>

// back-end
#include "../../be/contenitore/libromod.h"
#include "../../be/utenti/utenteavanzato.h"

class WGlobal {
public:
    // ModelLabel
    static QString fromUtente(const Utente*);
    static QString fromBook(const Libro*);

    // Box
    static const unsigned int MIN_BOX;
}; // WGlobal

#endif // WGLOBAL_H
