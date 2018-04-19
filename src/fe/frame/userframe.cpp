#include "userframe.h"

UserFrame::UserFrame(QWidget *parent, Biblioteca* biblioteca) : BWidget(parent, biblioteca), no_lbl(new QLabel(QString::fromStdString("Nome: " + b()->getUtente()->getNome()))), co_lbl(new QLabel(QString::fromStdString("Cognome: " + b()->getUtente()->getCognome()))) {
    // User Info Group Box
    QString title;
    if (b()->getUtente()->isAdmin()) title = "Admin Zone";
    else title = "User Info";
    QGroupBox* user_gb(new QGroupBox(title, this));
    QVBoxLayout* gb_l(new QVBoxLayout);
    QLabel *usr_lbl(new QLabel(QString::fromStdString("Username: " + b()->getUtente()->getUsername()), this)),
           *gr_lbl(new QLabel(this)),
           *cn_lbl(new QLabel(this));
    gb_l->addWidget(usr_lbl);
    gb_l->addWidget(no_lbl);
    gb_l->addWidget(co_lbl);
    gr_lbl->setText("Grado: " + QString::number(b()->getUtente()->getGrado()));
    gb_l->addWidget(gr_lbl);
    UtenteAvanzato* punt(dynamic_cast<UtenteAvanzato*>(b()->getUtente()));
    if (punt) {
        cn_lbl->setText("Numero di carta: " + QString::number(punt->getCardNumber()));
        gb_l->addWidget(cn_lbl);
    } // punt
    user_gb->setLayout(gb_l);

    // User Button
    QPushButton *logout_btn(new QPushButton("Logout", this)),
            *mod_btn(new QPushButton("Modifica Dati Utente", this)),
            *all_btn(new QPushButton("Restituisci tutti", this)),
            *del_btn(new QPushButton("Elimina utente", this));

    // layout
    QVBoxLayout* l(new QVBoxLayout);
    l->addWidget(user_gb);
    l->addSpacing(100);
    l->addStretch();
    l->addWidget(all_btn);
    l->addWidget(mod_btn);
    l->addWidget(logout_btn);
    l->addWidget(del_btn);

    setLayout(l);

    connect(logout_btn, SIGNAL(clicked()), this, SLOT(logout()));
    connect(mod_btn, SIGNAL(clicked()), this, SLOT(modifica()));
    connect(all_btn, SIGNAL(clicked()), this, SLOT(restituisciAll()));
    connect(del_btn, SIGNAL(clicked()), this, SLOT(deleteMe()));

} // UserFrame

void UserFrame::logout() {
    window()->close();
} // logout

void UserFrame::restituisciAll() {
    b()->restituisciAll();
    updateAll();
} // restituisciAll

void UserFrame::deleteMe() {
    b()->removeMe();
    logout();
} // deleteMe

void UserFrame::modifica() {
    SetUserData* s(new SetUserData(b()));
    s->show();
    connect(s, SIGNAL(updateAll()), this, SLOT(updateInfo()));
} // modifica

void UserFrame::updateInfo() {
    no_lbl->setText(QString::fromStdString("Nome: " + b()->getUtente()->getNome()));
    co_lbl->setText(QString::fromStdString("Cognome: " + b()->getUtente()->getCognome()));
} // updateInfo
