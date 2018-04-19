// be/strumenti/global.h

#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <vector>
#include <functional>
#include <cstdio>
#include <fstream>

#include <QDebug>

namespace std {

    // T non sottotipo di Obj
	template <class T>
    inline void hash_combine(std::size_t& seed, const T& v) {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2); // creo caos
    } // hash_combine

	// funzione per cryptare una std::string
	std::string crypt(const std::string&);

    // default file path
    std::string getRelPath(const std::string&);

    // elimina il file selezionato
    bool deleteFile(const std::string&);

    // ritorna le prime tot posizioni in s
    std::string taglia(const std::string&, unsigned int =15);

    // ritorna il testo estratto da un istream tra " ", in mancanza di " " ritorna la prima stringa in input
    std::string readText(std::istream&);
	
} // std namespace;

#endif
