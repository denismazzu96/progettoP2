#include "regwindow.h"

RegWindow::RegWindow(Biblioteca *b) : Window(b) {
    UserForm* form(new UserForm(this));

    QPushButton *ind_btn(new QPushButton("Indietro", this));

    QVBoxLayout *layout(new QVBoxLayout);
    layout->addWidget(form);
    layout->addWidget(ind_btn);

    setLayout(layout);

    // connect
    connect(form, SIGNAL(clicked(Obj*)), this, SLOT(registra(Obj*)));
    connect(ind_btn, SIGNAL(clicked()), this, SLOT(indietro()));
} // RegWindow

void RegWindow::registra(Obj *item) {
    Utente* u(dynamic_cast<Utente*>(item));
    if (u && b()->registraUtente(u))
        nextWindow(new InfoWindow(b()));
    else
        nextWindow(new RegWindow(b()));
} // registra

void RegWindow::indietro() {
    nextWindow(new LoginWindow(b()));
} // indietro
