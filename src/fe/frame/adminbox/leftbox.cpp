#include "leftbox.h"

LeftBox::LeftBox(QWidget *parent, Biblioteca *biblioteca, const QString& str) : BWidget(parent, biblioteca), list(new QListWidget(this)) {

    QPushButton* all(new QPushButton(str, this));
    connect(all, SIGNAL(clicked()), this, SLOT(deleteAll()));

    QVBoxLayout *l(new QVBoxLayout);
    l->addWidget(list);
    l->addWidget(all);
    setLayout(l);

    connect(list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(deleteItem(QListWidgetItem*)));

    list->setMinimumWidth(WGlobal::MIN_BOX);
} // LeftBox

QListWidget* LeftBox::getList() const {
    return list;
} // getList
