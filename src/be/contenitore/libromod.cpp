#include "libromod.h"

unsigned int LibroMod::resizeGrado(unsigned int newGr) {
    return (newGr<=Libro::MAX_GR && newGr>Libro::MIN_GR)?newGr:Libro::MIN_GR+1;
} // resizeGrado

LibroMod::LibroMod(const std::string& t, const std::string& a, const std::string& ce, const std::string& ge, unsigned int an, int c, int g) : Libro(t, a, ce, ge, an, c), grado(resizeGrado(g)) {} // LibroMod

unsigned int LibroMod::getGrado() const {
	return grado;
} // getGrado

std::size_t LibroMod::hash() const {
    std::size_t seed(Libro::hash());
	std::hash_combine(seed, grado);
	return seed;
} // hash

void LibroMod::print(std::ostream& os) const {
    os << 1;
	Libro::print(os);
    os << ' ' << grado;
} // print

void LibroMod::input(std::istream& is) {
    Libro::input(is);
    is >> grado;
    grado = resizeGrado(grado);
} // input

LibroMod* LibroMod::clone() const {
    return new LibroMod(*this);
} // clone
