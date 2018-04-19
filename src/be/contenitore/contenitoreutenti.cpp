#include "contenitoreutenti.h"

ContenitoreUtenti::ContenitoreUtenti(bool agg) : ContenitoreBase("", agg) {
    _init <Utente> ();
    _init <UtenteAvanzato> ();
    _init <Admin> ();
    refreshHash();
} // ContenitoreUtenti

ContenitoreUtenti::~ContenitoreUtenti() {
    if (ready() && isDiff()) {
        std::filebuf fbu, fbua, fba;
        fbu.open (Utente::PATH.data() ,std::ios::out);
        fbua.open (UtenteAvanzato::PATH.data() ,std::ios::out);
        fba.open (Admin::PATH.data() ,std::ios::out);
        std::ostream osu(&fbu), osua(&fbua), osa(&fba), *os(nullptr);

        for (auto it : *this) {
            if (it->isAdmin())
                os = &osa;
            else if (it->isUtenteAvanzato())
                os = &osua;
            else
                os = &osu;
            it->print(*os);
            (*os) << std::endl;
        } // for


        fbu.close();
        fbua.close();
        fba.close();
    } // if

    clear();
} // ~ContenitoreUtenti
