// be/contenitore/attributolibro.h

#ifndef ATTRIBUTILIBRO_H
#define ATTRIBUTILIBRO_H

#include <string>
#include "../strumenti/global.h"
#include "obj.h"

class AttributiLibro : public Obj{
private:
    std::string casaEd, genere;
    unsigned int anno;

    static const unsigned int MAX_CHAR, MIN_ANNO, MAX_ANNO, DEFAULT_ANNO;
public:
    AttributiLibro(const std::string& ="", const std::string& ="", unsigned int =1990);

    std::string getCasaEditrice() const;
    std::string getGenere() const;
    unsigned int getAnno() const;

    // Obj
    std::size_t hash() const;
    void print(std::ostream&) const;
    void input(std::istream&);
}; // Attributi Libro

#endif // ATTRIBUTILIBRO_H
