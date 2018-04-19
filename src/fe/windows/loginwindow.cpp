#include "loginwindow.h"

LoginWindow::LoginWindow(Biblioteca* biblioteca) : Window(biblioteca), user_txt(new QLineEdit(this)), psw_txt(new QLineEdit(this)) {
    // creazione QWidgets
    QLabel *title_lbl(new QLabel("Login", this)),
            *user_lbl(new QLabel("Username: ", this)),
            *psw_lbl(new QLabel("Password: ", this));

    // nascondo le password
    psw_txt->setEchoMode(QLineEdit::Password);
    psw_txt->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    // bottoni
    QPushButton *lgn_btn(new QPushButton("Login", this)),
            *rgs_btn(new QPushButton("Registrati", this));
    lgn_btn->setAutoDefault(true); // per poter premere invio
    rgs_btn->setAutoDefault(true);

    // creazione layout
    QGridLayout* g_layout(new QGridLayout);
    g_layout->addWidget(user_lbl, 0, 0);
    g_layout->addWidget(user_txt, 0, 1);
    g_layout->addWidget(psw_lbl, 1, 0);
    g_layout->addWidget(psw_txt, 1, 1);

    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(title_lbl);
    layout->addLayout(g_layout);
    layout->addWidget(lgn_btn);
    layout->addWidget(rgs_btn);

    setLayout(layout);

    // connect
    connect(user_txt, SIGNAL(selectionChanged()), user_txt, SLOT(clear()));
    connect(psw_txt, SIGNAL(selectionChanged()), psw_txt, SLOT(clear()));

    connect(lgn_btn, SIGNAL(clicked()), this, SLOT(login()));
    connect(rgs_btn, SIGNAL(clicked()), this, SLOT(registra()));
} // LoginWindow

void LoginWindow::login() {
    if (b()->login(user_txt->text().toStdString(), psw_txt->text().toStdString())) {
        nextWindow(new InfoWindow(b()));
    } else {
        user_txt->setText("Dati errati");
        psw_txt->clear();
    } // if-else
} // login

void LoginWindow::registra() {
    nextWindow(new RegWindow(b()));
} // registra
