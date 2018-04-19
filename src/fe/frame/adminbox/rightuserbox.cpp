#include "rightuserbox.h"

RightUserBox::RightUserBox(QWidget *parent, Biblioteca *biblioteca) : RightBox(parent, biblioteca, "Admin", new UserForm(parent, "Aggiungi", false)) {} // RightUserBox

void RightUserBox::setItem(Obj* item) {
    Utente* u(dynamic_cast <Utente*> (item));
    if (u) {
        Admin* a(new Admin(u->getUsername(), u->getPassword(), u->getNome(), u->getCognome(), false));
        b()->addAdmin(a);
        delete a;
        updateAll();
    } // if
} // setItem
