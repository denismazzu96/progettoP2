// be/utenti/utente.h

#ifndef UTENTE_H
#define UTENTE_H

#include <vector>
#include <string>
#include <fstream>

#include "persona.h"
#include "../contenitore/contenitore.h"
#include "../contenitore/libro.h" // inPrestito
#include "../contenitore/libromod.h"
#include "../strumenti/global.h" // hash_combine, crypt, getRelPath

class Utente : public Persona{
private:
	std::string username, password;
    Contenitore inPrestito;

	/* definisce se inPrestito è gia stato inizializzato
	 * cosi che un utente possa essere inizializzato (da costruttore o da operatore di input)
	 * senza dover inutilmente inizializzare in prestito con inutili chiamate a file
	 */
	bool init;
	void _init();
protected:
    static const unsigned int MIN_GRADO, MAX_GRADO;
public:
	static const std::string PATH; // Path del file degli utent
	/* PARAM username
	 * PARAM password
	 * PARAM nome
	 * PARAM cognome
	 */
    Utente(const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="", bool=true);
    Utente(const Utente&);

	// getter
	std::string getUsername() const;
	std::string getPassword() const;

    virtual unsigned int getGrado() const;

	// Obj
    virtual std::size_t hash() const;
    virtual void print(std::ostream&) const;
    virtual void input(std::istream&);
	bool operator == (const Utente&) const;
    bool operator != (const Utente&) const;

	// libri in prestito
    const std::vector<Libro*>* getLista();
    bool aggiungi(Libro*);
    bool restituisci(Libro*);

	// serve a eliminare il contenitore sia da memoria che da file (clear e poi distrugge il file)
	void deleteContenitore();

    // metodo di ricerca virtuale
    virtual std::vector<int> search(const std::vector<Libro*>*, const std::string&) const;

    virtual bool isAdmin() const;
    virtual bool isUtenteAvanzato() const;

    virtual Utente* clone() const;
}; // Utente

#endif
