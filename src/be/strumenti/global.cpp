// be/strumenti/global.cpp

#include "global.h"

std::string std::crypt(const std::string& ps) {
    std::string out(1, char((ps[0]*ps[0]% 25) + 97));
    for (unsigned int i(1); i < ps.length(); ++i)
        out.push_back(((ps[i] * out[i-1]) % 25) + 97);
    return out;
} // crypt

std::string std::getRelPath(const std::string& filename) {

#ifdef Q_OS_LINUX
    return "files/" + filename;
#else
    return "..\\Biblioteca\\files\\" + filename;
#endif
} // getRelPath

bool std::deleteFile(const std::string& path) {
	return remove(path.data());
} // deleteFile

std::string std::taglia(const std::string &str, unsigned int tot) {
    str.substr(0, tot);
    return str;
} // taglia

std::string std::readText(std::istream &is) {
    char c;
    std::string str;
    is >> std::skipws >> c;
    if (c==34) { // 34 == '"'
        is >> std::skipws >> c;
        while (c != 34) {
            str += c;
            is >> std::noskipws >> c;
        } // while
    } else {
        is >> std::noskipws >> str;
        str = c + str;
    } // if-else
    is >> std::skipws;
    return str;
} // readText
