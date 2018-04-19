// be/contenitore/contenitoreutenti.h

#ifndef CONTENITOREUTENTI_H
#define CONTENITOREUTENTI_H

#include "contenitorebase.h"
#include "../utenti/utente.h"
#include "../utenti/utenteavanzato.h"
#include "../utenti/admin.h"
#include <fstream>
#include "../strumenti/global.h"

class ContenitoreUtenti : public ContenitoreBase<Utente> {
private:
    template <class T> inline void _init() {
        Utente* punt(nullptr);
        std::filebuf fb;
        fb.open(T::PATH.data(), std::ios::in);
        if (fb.is_open()) {
            std::istream is(&fb);
            while (is.good()) {
                punt = new T();
                punt->input(is);
                if (!is.eof())
                    std::vector<Utente*>::push_back(punt);
                else
                    delete punt;
            } // while
        } // if
        fb.close();
    } // _init

public:
    ContenitoreUtenti(bool =true); // aggiornamento automatico
    ~ContenitoreUtenti();
}; // ConteintoreUtenti

#endif // CONTENITOREUTENTI_H
