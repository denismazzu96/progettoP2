#include "biblioteca.h"

Biblioteca::Biblioteca() : user(nullptr), c(new Contenitore), init(false) {
    ContenitoreUtenti cu;
    cu.push_back_ifndef(new Admin("admin", "admin", "default", "default"));
} // Biblioteca

Biblioteca::~Biblioteca() {
	delete user;
    delete c;
} // ~Biblioteca

void Biblioteca::init_vis () {
	if (init) {
		vis.clear();
		sup.clear();
		int i(0);
        for (auto it : *c) {
            if (controlloAccessi(it) && it->size()) {
				vis.push_back(it);
				sup.push_back(i);
			} // if
            i++;
		} // for
	} // if
} // init_vis

bool Biblioteca::login(const std::string& us, const std::string& ps) {
	if (init) return false; // ritorna falso se già inizializzato

    Utente temp(us, ps);
    ContenitoreUtenti cu;
    user = cu.search_clone(&temp);
    if (user) {
        init = true;
        init_vis();
    } // if
    return init;
} // login

bool Biblioteca::registraUtente(Utente* utente) {
	if (!init) { // init deve essere impostato a false
        ContenitoreUtenti cu;
        if (!cu.push_back_ifndef_clone(utente)) return false;
        init = true;
        user = utente;
        init_vis();
        return true;
    } else return false;
} // registraUtente

void Biblioteca::_adminCheck() const {
    if (!init || !user->isAdmin()) throw bad_admin();
} // _adminCheck

const Biblioteca& Biblioteca::operator =(const Biblioteca &b) { return b; } // _adminCheck

bool Biblioteca::addAdmin(Admin* a) {
	_adminCheck();
    ContenitoreUtenti cu;
    bool out(cu.push_back_ifndef(a));
    return out;
} // addAdmin

void Biblioteca::aggiornaUtente() const {
    ContenitoreUtenti cu;
    Utente* punt(cu.search(user));
    if (punt) {
        punt->setNome(user->getNome());
        punt->setCognome((user->getCognome()));
    } // punt
} // aggiornaUtente

bool Biblioteca::removeMe() {
	restituisciAll();
    ContenitoreUtenti cu;
    cu.erase(user);
	user->deleteContenitore();
	logout();
    return true;
} // removeMe

std::vector<Utente *>* Biblioteca::getListaUtenti() const {
    _adminCheck();
    return new ContenitoreUtenti;
} // getListaUtenti

// non puoi rimuovere te stesso
bool Biblioteca::removeUtente(Utente *u) const {
    _adminCheck();
    if ((*u) != (*user)) {
        ContenitoreUtenti cu;
        return cu.erase(u);
    } else return false;
} // removeUtente

Utente* Biblioteca::getUtente() const {
	return user;
} // getUtente

bool Biblioteca::controlloAccessi(Libro* l) const {
    return user->getGrado() >= l->getGrado();
} // controlloAccessi

const std::vector<Libro*>* Biblioteca::getListaLibri() const {
    return &vis;
} // getListaLibri

bool Biblioteca::daiInPrestito(unsigned int i) {
    if (i>sup.size() || !c->at(sup[i])->presta()) { // se non posso prestare il libro selezionato (mancanza di copie)
		init_vis();
		return false;
    } else if (!user->aggiungi(c->at(sup[i]))) { // se non posso darlo all'utente (gia in prestito)
        c->at(sup[i])->ritorna();
		return false;
    } else if (!c->at(sup[i])->size()) // se non ho piu copie devo aggiornare vis
		init_vis();
	return true;
} // daiInPrestito

bool Biblioteca::restituisci(Libro* l) {
    Libro* punt(c->search(l));
	if (!user->restituisci(l) || !punt) return false; // se non lo trovo o se l'utente non lo ha in prestito
	punt->ritorna();
	if (punt->size() == 1) init_vis(); // significa che ho aggiugnto un libro che prima aveva 0 copie -> bisogna aggiornare vis
	return true;
} // restituisci

std::vector<int> Biblioteca::search(const std::string& key) const {
    return user->search(&vis, key);
} // search

void Biblioteca::restituisciAll() {
    if (user->getLista()->size()) {
        restituisci(user->getLista()->at(0));
        restituisciAll();
    } // if
} // restituisciAll

Contenitore* Biblioteca::getContenitore() const {
	_adminCheck();
    return c;
} // getContenitore

bool Biblioteca::addLibro(Libro *l) {
	_adminCheck();
    bool b(c->push_back_ifndef(l));
    if (b) init_vis();
    return b;
} // addLibro

bool Biblioteca::modLibro(unsigned int i, Libro* l) {
    _adminCheck();
    removeLibro(i);
    return addLibro(l);
} // modLibro

void Biblioteca::removeLibro(unsigned int i) {
	_adminCheck();
    c->erase(c->begin()+i);
    init_vis();
} // addLibro

void Biblioteca::logout() {
	init = false;
} // logout

void Biblioteca::clearLibri() {
	_adminCheck();
    c->clear();
} // clearLibri

void Biblioteca::clearUtenti() const {
    ContenitoreUtenti cu;
    cu.clear();
} // clearUtenti
