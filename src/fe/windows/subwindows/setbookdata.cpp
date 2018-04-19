#include "setbookdata.h"

SetBookData::SetBookData(Biblioteca *biblioteca, int i) : Window(biblioteca), form(new BookForm(this, "Modifica")), id(i) {
    QPushButton* back_btn(new QPushButton("Indietro", this));

    // form
    Libro* li(b()->getContenitore()->at(id));
    form->getLineEdit("ti")->setText(QString::fromStdString(li->getTitolo()));
    form->getLineEdit("au")->setText(QString::fromStdString(li->getAutore()));
    form->getLineEdit("ce")->setText(QString::fromStdString(li->getCasaEditrice()));
    form->getLineEdit("ge")->setText(QString::fromStdString(li->getGenere()));
    form->getLineEdit("an")->setText(QString::number(li->getAnno()));
    form->getLineEdit("gr")->setText(QString::number(li->getGrado()));
    form->getLineEdit("nc")->setText(QString::number(li->size()));

    QVBoxLayout* l(new QVBoxLayout);
    l->addWidget(form);
    l->addWidget(back_btn);

    setLayout(l);

    connect(form, SIGNAL(clicked(Obj*)), this, SLOT(set(Obj*)));
    connect(back_btn, SIGNAL(clicked()), this, SLOT(hide()));
} // SetBookData

void SetBookData::set(Obj *obj) {
    Libro* punt(dynamic_cast<Libro*>(obj));
    if (punt) b()->modLibro(id, punt);
    close();
    updateAll();
} // set
