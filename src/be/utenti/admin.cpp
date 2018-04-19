#include "admin.h"

const std::string Admin::PATH = std::getRelPath("admin.txt");

Admin::Admin(const std::string& us, const std::string& ps, const std::string& no, const std::string& co, bool f) : UtenteAvanzato(UtenteAvanzato::MAX_GRADO, UtenteAvanzato::CN_DEF, us, ps, no, co, f) {} // admin

void Admin::print(std::ostream& os) const {
	Utente::print(os);
} // print

void Admin::input(std::istream& is) {
	Utente::input(is);
	setGrado(UtenteAvanzato::MAX_GRADO);
    setCardNumber(UtenteAvanzato::CN_DEF);
} // istream

bool Admin::isAdmin() const {
    return true;
} // isAdmin

Admin *Admin::clone() const {
    return new Admin(*this);
} // isAdmin
