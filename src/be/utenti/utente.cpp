// be/utenti/utente.cpp

#include "utente.h"

const std::string Utente::PATH = std::getRelPath("utenti.txt");

const unsigned int Utente::MIN_GRADO = 0;
const unsigned int Utente::MAX_GRADO = 5;

Utente::Utente(const std::string& us, const std::string& ps, const std::string& no, const std::string& co, bool cr) : Persona(no, co), username (std::taglia(us)), password(cr?std::crypt(std::taglia(ps)):std::taglia(ps)), init(false) {} // Utente

Utente::Utente(const Utente& u) : Persona(u), username (u.username), password (u.password), inPrestito(), init(false) {} // Utente

std::string Utente::getUsername() const {
	return username;
} // getUsername

std::string Utente::getPassword() const {
    return password;
} // getPassword

unsigned int Utente::getGrado() const {
    return MIN_GRADO;
} // getGrado

std::size_t Utente::hash() const {
    std::size_t seed(Persona::hash());
	std::hash_combine(seed, username);
	std::hash_combine(seed, password);
	return seed;
} // hash

void Utente::print(std::ostream& os) const {
    os << username << ' ' << password << ' ' << *this;
} // print

void Utente::input(std::istream& is) {
    is >> username >> password >> *this;
} // input

bool Utente::operator == (const Utente& u) const {
    return username == u.username && password == u.password;
} // operator ==

bool Utente::operator !=(const Utente &u) const {
    return username != u.username || password != u.password;
} // operator !=

void Utente::_init() {
	if (!init) {
        std::string path = std::getRelPath("utenti/" + username + ".txt");
        inPrestito.changePath(path);
		init = true;
	} // if
} // _init

const std::vector<Libro*>* Utente::getLista() {
	_init();
    return &inPrestito;
} // getLista

bool Utente::aggiungi(Libro* l) {
	_init();
    return inPrestito.push_back_ifndef_clone(l);
} // aggiungi

bool Utente::restituisci(Libro* l) {
	_init();
	return inPrestito.erase(l); // lo toglie solo se esiste
} // aggiungi

void Utente::deleteContenitore() {
	inPrestito.clear(); // svuota
	std::deleteFile(inPrestito.getPath()); // elimina file
    inPrestito.setReady(false); // ferma l'aggiornamento automatico del file
} // deleteContenitore

std::vector<int> Utente::search(const std::vector<Libro*> *v, const std::string &key) const {
    std::vector<int> out;
    int i(0);
    for (auto it : *v) {
        if (it->getTitolo() == key || it->getAutore() == key)
            out.push_back(i);
        i++;
    } // for
    return out;
} // search

bool Utente::isUtenteAvanzato() const {
    return false;
} // isUtenteAvanzato

Utente* Utente::clone() const {
    return new Utente(*this);
} // clone

bool Utente::isAdmin() const {
    return false;
} // isAdmin
