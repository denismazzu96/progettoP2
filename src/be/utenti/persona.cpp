// be/utenti/persona.cpp

#include "persona.h"

Persona::Persona(const std::string& n, const std::string& c) : nome(std::taglia(n)),  cognome(std::taglia(c)) {} // Persona

std::ostream& operator << (std::ostream& os, const Persona& p) {
    return os << p.nome << ' ' << p.cognome;
} // operator <<

std::istream& operator >> (std::istream& is, Persona& p) {
    is >> p.nome;
    is >> p.cognome;
    return is;
} // operator >>

std::string Persona::getNome() const {
	return nome;
} // getNome

std::string Persona::getCognome() const {
	return cognome;
} // getCognome

void Persona::setNome(const std::string &newNome) {
    nome = newNome;
} // setNome

void Persona::setCognome(const std::string &newCognome) {
    cognome = newCognome;
} // setCognome

std::size_t Persona::hash() const {
	std::size_t seed(0);
	std::hash_combine(seed, nome);
	std::hash_combine(seed, cognome);
	return seed;
} // hash
