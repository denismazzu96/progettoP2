// be/utenti/utenteavanzato.cpp

#include "utenteavanzato.h"

const std::string UtenteAvanzato::PATH = std::getRelPath("utentiavanzati.txt");
const unsigned int UtenteAvanzato::CN_DEF = 0;

UtenteAvanzato::UtenteAvanzato(unsigned int g, std::size_t cn, const std::string& us, const std::string& ps, const std::string& no, const std::string& co, bool f) : Utente(us, ps, no, co, f), grado((g>UtenteAvanzato::MIN_GRADO && g<Utente::MAX_GRADO)?g:Utente::MIN_GRADO+1), card_number(cn) {} // UtenteAvanzato

void UtenteAvanzato::setGrado(unsigned int newgrado) {
	grado = newgrado;
} // setGrado

unsigned int UtenteAvanzato::getGrado() const {
	return grado;
} // getGrado

void UtenteAvanzato::setCardNumber(unsigned int newcn) {
    card_number = newcn;
} // setCardNumber

std::size_t UtenteAvanzato::getCardNumber() const {
    return card_number;
} // getCardNumber

size_t UtenteAvanzato::hash() const {
    std::size_t seed(Utente::hash());
	std::hash_combine(seed, grado);
    std::hash_combine(seed, card_number);
	return seed;
} // hash

void UtenteAvanzato::print(std::ostream& os) const {
    os << grado << ' ' << card_number << ' ';
	Utente::print(os);
} // print

void UtenteAvanzato::input(std::istream& is) {
	is >> grado;
    is >> card_number;
	Utente::input(is);
    if (grado>Utente::MAX_GRADO || grado < Utente::MIN_GRADO) grado = Utente::MIN_GRADO+1;
} // istream

std::vector<int> UtenteAvanzato::search(const std::vector<Libro*> *v, const std::string &key) const {
    std::vector<int> out;
    int i(0);
    for (auto it : *v) {
        if (it->getTitolo().find(key) != std::string::npos ||
                it->getAutore().find(key) != std::string::npos ||
                it->getCasaEditrice().find(key) != std::string::npos ||
                it->getGenere().find(key) != std::string::npos ||
                it->getAnno() == (unsigned int)atoi(key.c_str()))
            out.push_back(i);
        i++;
    } // for
    return out;
} // search

bool UtenteAvanzato::isUtenteAvanzato() const {
    return true;
} // isUtenteAvanzato

UtenteAvanzato* UtenteAvanzato::clone() const {
    return new UtenteAvanzato(*this);
} // clone
