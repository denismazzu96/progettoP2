#include "bookform.h"

BookForm::BookForm(QWidget* parent, const QString& str) : Form(parent), au_txt(new QLineEdit(this)), ti_txt(new QLineEdit(this)), ce_txt(new QLineEdit(this)), ge_txt(new QLineEdit(this)), an_txt(new QLineEdit(this)), gr_txt(new QLineEdit(this)), nc_txt(new QLineEdit(this)) {
    QLabel *title_lbl(new QLabel(str, this)),
            *au_lbl(new QLabel("Autore:", this)),
            *ti_lbl(new QLabel("Titolo:", this)),
            *ce_lbl(new QLabel("Casa Editrice:", this)),
            *ge_lbl(new QLabel("Genere:", this)),
            *an_lbl(new QLabel("Anno:", this)),
            *gr_lbl(new QLabel("Grado:", this)),
            *nc_lbl(new QLabel("Copie Disponibili:", this));

    QPushButton *reg_btn(new QPushButton(str + " Libro", this));
    reg_btn->setAutoDefault(true);

    QGridLayout *grid(new QGridLayout);
    grid->addWidget(au_lbl, 0, 0);
    grid->addWidget(au_txt, 0, 1);
    grid->addWidget(ti_lbl, 1, 0);
    grid->addWidget(ti_txt, 1, 1);
    grid->addWidget(ce_lbl, 2, 0);
    grid->addWidget(ce_txt, 2, 1);
    grid->addWidget(ge_lbl, 3, 0);
    grid->addWidget(ge_txt, 3, 1);
    grid->addWidget(an_lbl, 4, 0);
    grid->addWidget(an_txt, 4, 1);
    grid->addWidget(gr_lbl, 5, 0);
    grid->addWidget(gr_txt, 5, 1);
    grid->addWidget(nc_lbl, 6, 0);
    grid->addWidget(nc_txt, 6, 1);

    QVBoxLayout *layout(new QVBoxLayout);
    layout->addWidget(title_lbl);
    layout->addStretch(0);
    layout->addLayout(grid);
    layout->addWidget(reg_btn);

    setLayout(layout);

    // connect
    connect(reg_btn, SIGNAL(clicked()), this, SLOT(_clicked()));
}

QLineEdit *BookForm::getLineEdit(const QString &sigla) const {
    if (sigla == "au")
        return au_txt;
    if (sigla == "ti")
        return ti_txt;
    if (sigla == "ce")
        return ce_txt;
    if (sigla == "ge")
        return ge_txt;
    if (sigla == "an")
        return an_txt;
    if (sigla == "gr")
        return gr_txt;
    if (sigla == "nc")
        return nc_txt;
    return nullptr;
} // BookForm

void BookForm::_clicked() {
    Libro*l(nullptr);
    if (!au_txt->text().isEmpty() && !ti_txt->text().isEmpty() && !ce_txt->text().isEmpty() && !ge_txt->text().isEmpty() && !an_txt->text().isEmpty() && !nc_txt->text().isEmpty()) {
        if (gr_txt->text().isEmpty() || gr_txt->text().toInt() == 0)
            l = new Libro(
                ti_txt->text().toStdString(),
                au_txt->text().toStdString(),
                ce_txt->text().toStdString(),
                ge_txt->text().toStdString(),
                an_txt->text().toInt(),
                nc_txt->text().toInt());
        else
            l = new LibroMod(
                ti_txt->text().toStdString(),
                au_txt->text().toStdString(),
                ce_txt->text().toStdString(),
                ge_txt->text().toStdString(),
                an_txt->text().toInt(),
                nc_txt->text().toInt(),
                gr_txt->text().toInt());
    } // if
    au_txt->clear();
    ti_txt->clear();
    ce_txt->clear();
    ge_txt->clear();
    an_txt->clear();
    gr_txt->clear();
    nc_txt->clear();

    clicked(l);
} // _clicked
