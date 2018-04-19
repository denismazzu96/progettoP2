// be/contenitore/libromod.h

#ifndef LIBROMOD_H
#define LIBROMOD_H

#include <string>
#include <fstream>
#include "../strumenti/global.h"

#include "libro.h"

class LibroMod : public Libro {
private:
    unsigned int grado; // numero copie disponibili

    static unsigned int resizeGrado(unsigned int);
public:
    LibroMod(const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="", unsigned int =1990, int =0, int =0);

    unsigned int getGrado() const;

	// Obj
	std::size_t hash() const;
	void print(std::ostream&) const;
    void input(std::istream&);

    LibroMod* clone() const;
}; // LibroMod

#endif
