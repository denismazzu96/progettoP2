// be/utenti/utenteavanzato.h

#ifndef UTENTEAVANZATO_H
#define UTENTEAVANZATO_H

#include "utente.h"
#include <string>
#include <fstream>
#include "../strumenti/global.h"

#include <QDebug>

class UtenteAvanzato : public Utente {
private:
    unsigned int grado;
    std::size_t card_number;
protected:
    static const unsigned int CN_DEF;
	void setGrado(unsigned int);
    void setCardNumber(unsigned int);
public:
	static const std::string PATH; // Path del file degli utenti avanzati
	/* PARAM grado
	 * PARAM username
	 * PARAM password
	 * PARAM nome
	 * PARAM cognome
	 */
    UtenteAvanzato(unsigned int =Utente::MIN_GRADO, std::size_t card_number =0, const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="", bool =true);

    unsigned int getGrado() const;
    std::size_t getCardNumber() const;

	// Obj
	std::size_t hash() const;
	void print(std::ostream&) const;
    void input(std::istream&);

    std::vector<int> search(const std::vector<Libro*> *, const std::string &) const;

    bool isUtenteAvanzato() const;

    UtenteAvanzato* clone() const;
}; // UtenteAvanzato

#endif
