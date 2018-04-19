// be/eccezioni/bad_admin.h

#ifndef BAD_ADMIN_H
#define BAD_ADMIN_H

#include <exception>

class bad_admin : public std::exception {
public:
	const char* what() const noexcept;
}; // bad_admin

#endif