#include "userform.h"

UserForm::UserForm(QWidget* parent, const QString &button, bool t) : Form(parent), us_txt(new QLineEdit(this)), ps_txt(new QLineEdit(this)), no_txt(new QLineEdit(this)), co_txt(new QLineEdit(this)), gr_txt(new QLineEdit(this)), cn_txt(new QLineEdit(this)), type(t) {
    QLabel *title_lbl(new QLabel("Registrazione", this)),
            *us_lbl(new QLabel("Username:", this)),
            *ps_lbl(new QLabel("Password:", this)),
            *no_lbl(new QLabel("Nome:", this)),
            *co_lbl(new QLabel("Cognome:", this)),
            *gr_lbl(new QLabel("Grado:", this)),
            *gr_aux_lbl(new QLabel("*inserire il grado solo se si desidera un'utente avanzato", this)),
            *cn_lbl(new QLabel("Numero di Carta:", this)),
            *cn_aux_lbl(new QLabel("*inserire il numero di carta solo se si desidera un'utente avanzato", this));

    QPushButton *reg_btn(new QPushButton(button, this));

    QGridLayout *grid(new QGridLayout);
    grid->addWidget(us_lbl, 0, 0);
    grid->addWidget(us_txt, 0, 1);
    grid->addWidget(ps_lbl, 1, 0);
    grid->addWidget(ps_txt, 1, 1);
    grid->addWidget(no_lbl, 2, 0);
    grid->addWidget(no_txt, 2, 1);
    grid->addWidget(co_lbl, 3, 0);
    grid->addWidget(co_txt, 3, 1);
    grid->addWidget(gr_aux_lbl, 4, 0, 1, 2);
    grid->addWidget(gr_lbl, 5, 0);
    grid->addWidget(gr_txt, 5, 1);
    grid->addWidget(cn_aux_lbl, 6, 0, 1, 2);
    grid->addWidget(cn_lbl, 7, 0);
    grid->addWidget(cn_txt, 7, 1);
    if (!type) {
        gr_lbl->hide();
        gr_txt->hide();
        cn_lbl->hide();
        cn_txt->hide();
        gr_aux_lbl->hide();
        cn_aux_lbl->hide();
    } // if

    QVBoxLayout *layout(new QVBoxLayout);
    layout->addWidget(title_lbl);
    layout->addStretch(0);
    layout->addLayout(grid);
    layout->addWidget(reg_btn);

    setLayout(layout);

    // connect
    connect(reg_btn, SIGNAL(clicked()), this, SLOT(_clicked()));
} // UserForm

void UserForm::_clicked() {
    Utente* u(nullptr);

    if (!us_txt->text().isEmpty() && !no_txt->text().isEmpty() && !ps_txt->text().isEmpty() && !co_txt->text().isEmpty()) {
        if (!gr_txt->text().isEmpty() && !cn_txt->text().isEmpty())
            u = new UtenteAvanzato(
                gr_txt->text().toInt(),
                cn_txt->text().toInt(),
                us_txt->text().toStdString(),
                ps_txt->text().toStdString(),
                no_txt->text().toStdString(),
                co_txt->text().toStdString());
        else
            u = new Utente(
                us_txt->text().toStdString(),
                ps_txt->text().toStdString(),
                no_txt->text().toStdString(),
                co_txt->text().toStdString());
    } // if

    gr_txt->clear();
    cn_txt->clear();
    us_txt->clear();
    ps_txt->clear();
    no_txt->clear();
    co_txt->clear();

    clicked(u);
} // _clicked
