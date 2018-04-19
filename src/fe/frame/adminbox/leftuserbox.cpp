#include "leftuserbox.h"

LeftUserBox::LeftUserBox(QWidget *parent, Biblioteca *biblioteca) : LeftBox(parent, biblioteca, "Eliminare tutti gli Utenti") {
    updateList();
} // LeftUserBox

void LeftUserBox::updateList() {
    getList()->clear();
    int i(0);
    auto lista(b()->getListaUtenti());
    for (auto it : *lista)
        new QListWidgetItem(WGlobal::fromUtente(it), getList(), i++);
    delete lista;
} // updateList

void LeftUserBox::deleteAll() {
    b()->clearUtenti();
    updateList();
} // deleteAll

void LeftUserBox::deleteItem(QListWidgetItem* item) {
    int index(item->type());
    auto lista(b()->getListaUtenti());
    b()->removeUtente(lista->at(index));
    delete lista;
    updateList();
    Message(this, "Eliminazione Utente", "Utente eliminato dal Sistema");
} // deleteItem
