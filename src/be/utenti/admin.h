// be/contenitore/admin.h

#ifndef ADMIN_H
#define ADMIN_H

#include <string>

#include "utenteavanzato.h"

class Admin : public UtenteAvanzato {
public:
	static const std::string PATH;
    /* PARAM username
	 * PARAM password
	 * PARAM nome
	 * PARAM cognome
	 */
    Admin(const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="", bool =true);

	void print(std::ostream&) const;
    void input(std::istream&);

    bool isAdmin() const;

    Admin* clone() const;
}; // Admin

#endif
