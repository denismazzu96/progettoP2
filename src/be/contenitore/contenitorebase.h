// fe/contenitore/contenitorebase.h

#ifndef CONTENITOREBASE_H
#define CONTENITOREBASE_H

#include <vector>
#include <string>
#include "../strumenti/global.h"

template <class T>
class ContenitoreBase : public std::vector<T*> {
private:
    bool r;
    std::string path;
    std::size_t beginHash;
protected:
    inline bool ready() const {
        return r;
    } // ready
public:
    inline ContenitoreBase(const std::string& p="", bool a=true) : r(a), path(p), beginHash(0) {} // ContenitoreBase

    inline ~ContenitoreBase() {
        clear();
    } // ~ContenitoreBase

    const char* getPath() const {
        return path.data();
    } // getPath

    void setPath(const std::string& p) {
        path = p;
    } // setPath

    void setReady(bool a=true) {
        r=a;
    } // setReady

    std::size_t hash() const {
        std::size_t seed(0);
        for (auto it : *this)
            std::hash_combine(seed, it->hash());
        return seed;
    } // hash

    void refreshHash() {
        beginHash = hash();
    } // refreshHash

    bool isDiff() const {
        return beginHash != hash();
    } // isDiff

    inline T* search (T* t) {
        for (auto it : *this)
            if ((*it) == (*t))
                return &(*it);
        return nullptr;
    } // search_h

    inline T* search_clone (T* t) {
        T* ptr(search(t));
        if (ptr)
            return ptr->clone();
        else
            return nullptr;
    } // search_h

    inline bool exist (T* t) const {
        for (auto it : *this)
            if ((*it) == (*t))
                return true;
        return false;
    } // exist

    inline bool push_back_ifndef (T* t) {
        bool trovato(true);
        for (auto it : *this)
            if ((*it) == (*t))
                trovato = false;
        if (trovato) std::vector<T*>::push_back(t);
        return trovato;
    } // push_back_ifndef

    inline void push_back_clone (T* t) {
        std::vector<T*>::push_back(t->clone());
    } // push_back_clone

    inline bool push_back_ifndef_clone (T* t) {
        return push_back_ifndef(t->clone());
    } // push_back_ifndef

    inline bool erase (T* t) {
        bool trovato(false);
        for (auto it = std::vector<T*>::begin(); !trovato && it != std::vector<T*>::end(); it++)
            if ((**it) == (*t)) {
                trovato = true;
                erase(it);
            } // if
        return trovato;
    } // erase

    typename std::vector<T*>::iterator erase(typename std::vector<T*>::iterator iterator) {
        T* ptr(*iterator);
        auto out(std::vector<T*>::erase(iterator));
        delete ptr;
        return out;
    } // erase

    void clear() {
        if (std::vector<T*>::size()) {
            erase(std::vector<T*>::begin());
            clear();
        } // if
    } // clear

}; // ContenitoreBase

#endif // CONTENITOREBASE_H
