#include "libro.h"

const unsigned int Libro::MAX_GR = 5;
const unsigned int Libro::MIN_GR = 0;

const std::string Libro::PATH = std::getRelPath("libri.txt");

Libro::Libro(const std::string& t, const std::string& a, const std::string& ce, const std::string& g, unsigned int an, unsigned int nc)
    : AttributiLibro(ce, g, an), titolo(std::taglia(t)), autore(std::taglia(a)), ncopie(nc) {} // Libro

std::string Libro::getTitolo() const {
	return titolo;
} // getTitolo

std::string Libro::getAutore() const {
	return autore;
} // getAutore

unsigned int Libro::size() const {
    return ncopie;
} // size

bool Libro::presta() {
    bool out;
    if((out = (ncopie != 0)))
        ncopie--;
    return out;
} // presta

void Libro::ritorna() {
    ncopie++;
} // ritorna

unsigned int Libro::getGrado() const {
    return MIN_GR;
} // getGrado

std::size_t Libro::hash() const {
    std::size_t seed(AttributiLibro::hash());
	std::hash_combine(seed, titolo);
    std::hash_combine(seed, autore);
    std::hash_combine(seed, ncopie);
	return seed;
} // hash

void Libro::print(std::ostream& os) const {
    os << 0 << ' ' << '"' << titolo << "\" " << '"' << autore << "\" ";
    AttributiLibro::print(os);
    os << ncopie;
} // print

void Libro::input(std::istream& is) {    
    titolo = std::readText(is); // is >> titolo;
    autore = std::readText(is);
    AttributiLibro::input(is);
    is >> ncopie;
} // input

bool Libro::operator == (const Libro& l) const {
    return titolo == l.titolo && autore == l.autore;
} // operator ==

Libro* Libro::clone() const {
    return new Libro(*this);
} // clone
