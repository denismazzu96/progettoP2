#include "leftbookbox.h"

LeftBookBox::LeftBookBox(QWidget *parent, Biblioteca *biblioteca) : LeftBox(parent, biblioteca, {"Eliminare tutti i libri"}) {
    updateList();
} // LeftUserBox

void LeftBookBox::updateList() {
    getList()->clear();
    int i(0);
    for (auto it : *b()->getContenitore())
        new QListWidgetItem(WGlobal::fromBook(it), getList(), i++);
} // updateList

void LeftBookBox::deleteAll() {
    b()->clearLibri();
    updateList();
} // deleteAll

void LeftBookBox::deleteItem(QListWidgetItem* item) {
    int index(item->type());
    QMessageBox* msg(new QMessageBox(this));
    msg->setText("Libro Selezionato");
    msg->setInformativeText("Decidere se modificare o eliminare il libro scelto.");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg->button(QMessageBox::Yes)->setText("Modifica");
    msg->button(QMessageBox::No)->setText("Elimina");
    msg->exec();
    if (msg->clickedButton() == msg->button(QMessageBox::No)) {
        b()->removeLibro(index);
        Message msg(this, "Eliminazione Libro", "Libro eliminato dal Sistema");
        updateList();
        updateAll();
    } else if (msg->clickedButton() == msg->button(QMessageBox::Yes)) {
        SetBookData* box(new SetBookData(b(), index));
        connect(box, SIGNAL(updateAll()), this, SLOT(updateList()));
        connect(box, SIGNAL(updateAll()), this, SIGNAL(updateAll()));
        box->show();
    } // if-elseif

} // deleteItem
