#include "contenitore.h"

void Contenitore::_init() {
    Libro* punt(nullptr);
    int i;
    std::filebuf fb;
    fb.open(getPath(), std::ios::in);
    if (fb.is_open()) {
        std::istream is(&fb);
        while (is.good()) {
            is >> i;
            if (!is.eof()) {
                if (i == 0)
                    punt = new Libro();
                else
                    punt = new LibroMod();
                punt->input(is);
                if (!is.eof())
                    std::vector<Libro*>::push_back(punt);
                else
                    delete punt;
            } // if
        } // while
    } // if
    fb.close();
    refreshHash();
} // _init

Contenitore::Contenitore(bool agg) : ContenitoreBase(Libro::PATH, agg) {
    _init();
} // Contenitore

void Contenitore::changePath(const std::string& path) {
    std::vector<Libro*>::clear();
    setPath(path);
    _init();
} // Contenitore

Contenitore::~Contenitore() {
    if (ready() && isDiff()) {
        std::filebuf fb;
        fb.open (getPath() ,std::ios::out);
        std::ostream os(&fb);

        for (auto it : *this) {
            it->print(os);
            os << std::endl;
        } // for

        fb.close();
    } // if

    clear();
} // ~Contenitore
