// be/contenitore/libro.h

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <fstream>
#include "../strumenti/global.h" // std::hash_combine
#include <functional> // std::hash, std::size_t
#include "attributilibro.h"

class Libro : public AttributiLibro {
private:
    std::string titolo, autore;
    unsigned int ncopie;

protected:
    static const unsigned int MAX_GR, MIN_GR;
public:
    static const std::string PATH; // Path del file dei libri
	/* PARAM titolo
	 * PARAM autore
     * PARAM casaEd
     * PARAM genere
     * PARAM anno
	 */
    Libro(const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="", unsigned int =0, unsigned int =0);

	// getter
	std::string getTitolo() const;
    std::string getAutore() const;

    unsigned int size() const;
    bool presta(); // decrementa il contatore
    void ritorna(); // incrementa il contatore

    virtual unsigned int getGrado() const;

	// Obj
    virtual std::size_t hash() const;
    virtual void print(std::ostream&) const;
    virtual void input(std::istream&);
	bool operator == (const Libro&) const;

    virtual Libro* clone() const;
}; // Libro

#endif
