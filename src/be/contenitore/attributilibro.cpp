#include "attributilibro.h"

const unsigned int AttributiLibro::MAX_CHAR = 20;
const unsigned int AttributiLibro::MIN_ANNO = 1000;
const unsigned int AttributiLibro::MAX_ANNO = 2017;
const unsigned int AttributiLibro::DEFAULT_ANNO = 0;

AttributiLibro::AttributiLibro(const std::string &ce, const std::string &g, unsigned int an) : casaEd(std::taglia(ce)), genere(std::taglia(g)), anno((an>MIN_ANNO&&an<MAX_ANNO)?an:DEFAULT_ANNO) {} // AttributiLibro

std::string AttributiLibro::getCasaEditrice() const {
    return casaEd;
} // getCasaEditrice

std::string AttributiLibro::getGenere() const {
    return genere;
} // getGenere

unsigned int AttributiLibro::getAnno() const {
    return anno;
} // getAnno

std::size_t AttributiLibro::hash() const {
    std::size_t seed(0);
    std::hash_combine(seed, casaEd);
    std::hash_combine(seed, genere);
    std::hash_combine(seed, anno);
    return seed;
} // hash

void AttributiLibro::print(std::ostream& os) const {
    if (casaEd.find(' '))
        os << '"' << casaEd << "\" ";
    else
        os << casaEd << ' ';
    os << genere << ' ' << anno << ' ';
} // print

void AttributiLibro::input(std::istream& is) {
    casaEd = std::readText(is);
    is >> genere;
    is >> anno;
} // input
