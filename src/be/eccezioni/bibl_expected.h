// be/eccezioni/bibl_expected.h

#ifndef BIBL_EXPECTED_H
#define BIBL_EXPECTED_H

#include <exception>

class bibl_expected : public std::exception {
public:
    const char* what() const noexcept;
}; // bibl_expected

#endif // BIBL_EXPECTED_H
