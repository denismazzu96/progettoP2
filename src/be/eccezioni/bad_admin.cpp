#include "bad_admin.h"

const char* bad_admin::what() const noexcept {
	return "admin required.";
} // what