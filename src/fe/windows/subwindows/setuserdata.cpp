#include "setuserdata.h"

SetUserData::SetUserData(Biblioteca *biblioteca) : Window(biblioteca), no_txt(new QLineEdit(this)), co_txt(new QLineEdit(this)) {
    QLabel* ttl_lbl(new QLabel("Modifica dati Utente", this)),
            *no_lbl(new QLabel("Nome: ", this)),
            *co_lbl(new QLabel("Cognome: ", this));

    QPushButton *go_btn(new QPushButton("Modifica", this)),
            *back_btn(new QPushButton("Indietro", this));
    go_btn->setDefault(true);

    QGridLayout* grid(new QGridLayout);
    grid->addWidget(no_lbl, 0, 0);
    grid->addWidget(no_txt, 0, 1);
    grid->addWidget(co_lbl, 1, 0);
    grid->addWidget(co_txt, 1, 1);
    grid->addWidget(go_btn, 2, 0);
    grid->addWidget(back_btn, 2, 1);

    QVBoxLayout* l(new QVBoxLayout);
    l->addWidget(ttl_lbl);
    l->addLayout(grid);

    setLayout(l);

    connect(go_btn, SIGNAL(clicked()), this, SLOT(set()));
    connect(back_btn, SIGNAL(clicked()), this, SLOT(hide()));
} // SetUserData

void SetUserData::set() {
    if (!no_txt->text().isEmpty())
        b()->getUtente()->setNome(no_txt->text().toStdString());
    if (!co_txt->text().isEmpty())
        b()->getUtente()->setCognome(co_txt->text().toStdString());
    b()->aggiornaUtente();
    updateAll();
    close();
} // set
