// be/utenti/persona.h

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <fstream>
#include "../contenitore/obj.h"
#include "../strumenti/global.h" // per hash_combine

class Persona : public Obj{
    friend std::ostream& operator << (std::ostream&, const Persona&);
    friend std::istream& operator >> (std::istream&, Persona&);
private:
    std::string nome, cognome;
public:
	/* PARAM nome
	 * PARAM cognome
	 */
	Persona(const std::string&, const std::string&);
	Persona() = default;

	// getter
	// restituisce il nome della persona
	std::string getNome() const;
	// restituisce il cognome della persona
	std::string getCognome() const;

    void setNome(const std::string&);
    void setCognome(const std::string&);

    std::size_t hash() const;
}; // Persona

#endif
