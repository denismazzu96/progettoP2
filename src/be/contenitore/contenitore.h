// be/contenitore/contenitore.h

#ifndef CONTENITORE_H
#define CONTENITORE_H

#include "contenitorebase.h"
#include "libro.h"
#include "libromod.h"

class Contenitore : public ContenitoreBase<Libro> {
private:
    void _init();
public:
    Contenitore(bool =true);
    ~Contenitore();

    void changePath(const std::string&);
}; // Contenitore

#endif
