#include "rightbookbox.h"

RightBookBox::RightBookBox (QWidget *parent, Biblioteca *biblioteca) : RightBox(parent, biblioteca, "Libro", new BookForm(parent)) {} // RightBookBox

void RightBookBox::setItem(Obj* item) {
    Libro* u(dynamic_cast <Libro*> (item));
    if (u) {
        b()->addLibro(u);
        updateAll();
    } // if
} // setItem
