#include "rightbox.h"

RightBox::RightBox(QWidget *parent, Biblioteca *biblioteca, const QString& str, Form* form) : BWidget(parent, biblioteca) {
    QString s("Aggiungi " + str);
    QGroupBox* gb(new QGroupBox(s, this));
    gb->setMinimumWidth(WGlobal::MIN_BOX);
    QVBoxLayout* gb_l(new QVBoxLayout);

    gb_l->addWidget(form);

    gb->setLayout(gb_l);
    QVBoxLayout* l(new QVBoxLayout);
    l->addWidget(gb);
    setLayout(l);

    connect(form, SIGNAL(clicked(Obj*)), this, SLOT(setItem(Obj*)));
} // RightBox
