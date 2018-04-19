// be/biblioteca.h

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// strumenti
#include "strumenti/global.h"

// c++
#include <string>
#include <vector>
#include <typeinfo>

// eccezioni
#include "eccezioni/bad_admin.h"

// utenti
#include "utenti/utente.h"
#include "utenti/utenteavanzato.h"
#include "utenti/admin.h"

// contenitore
#include "contenitore/contenitore.h"
#include "contenitore/contenitoreutenti.h"
#include "contenitore/libro.h"
#include "contenitore/libromod.h" 

#include <iostream>

class Biblioteca {
private:
	Utente* user; // utente attivo nell'applicativo
    Contenitore* c; // contenitore principale

    std::vector<Libro*> vis; // contenitore libri visibili all'utente
	std::vector<int> sup; // definisce la locazione di un oggetto di vis in c (vis[i] "==" c[sup[i]])

	void init_vis(); // inizializza vis se l'utente è attivo in O(n)

	// passato un LibroMod ritorna true se accessibile dall'utente user (anche se non disponibile in copia)
    bool controlloAccessi(Libro*) const;

	void _adminCheck() const;

	bool init; // definisce se si è inizializzata la biblioteca con un utente

    // privati
    Biblioteca(const Biblioteca&) =default;
    const Biblioteca& operator =(const Biblioteca&);
public:
	Biblioteca();
	~Biblioteca();

	// ritorna true se l'operazione è andata a buon fine
    bool login(const std::string&, const std::string&); // se free == true non serve cryptare la password prima di confrontarla

	// sequenze di passaggi 1: Biblioteca() -> login(username, password) -> ... sequenze di operazioni disponibili ... -> logout() -> ~Biblioteca() -> fine.
	// sequenze di passaggi 2: Biblioteca() -> registraUtente(Utente*) -> login(username, password) (chiamata implicita) -> ... sequenze di operazioni disponibili ... -> logout() -> ~Biblioteca() -> fine.

	// getter
    Utente* getUtente() const;
    const std::vector<Libro*>* getListaLibri() const; // O(1)

	// per tutti gli utenti
	// l'indice fa riferimento alla lista ritornata con getListaLibri()
	bool daiInPrestito(unsigned int i); // utente prende in prestito un libro in O(1) ammortizzato
	// se il libro non esiste in c verra solo rimosso dalla lista dell'utente
    bool restituisci(Libro*); // in O(n) sul contenitore principale
	void restituisciAll(); 

    std::vector<int> search(const std::string&) const; // indici riferiti alla lista ritornata da getListaLibri()

	// si possono registrare solo utenti o utentiavanzati
	bool registraUtente(Utente*);
	bool removeMe();

	// solo per admin
    std::vector<Utente*>* getListaUtenti() const;
    bool removeUtente(Utente*) const;
    bool addAdmin(Admin*);
    void aggiornaUtente() const;
    Contenitore* getContenitore() const;
    bool addLibro(Libro*);
    bool modLibro(unsigned int, Libro*);
	void removeLibro(unsigned int); // indice fa riferimento a getContenitore
	void clearLibri();
    void clearUtenti() const;

	void logout();
}; // Biblioteca

#endif
