#include "searchbox.h"

SearchBox::SearchBox(Biblioteca *biblioteca, const QString& str) : Window(biblioteca), list(new QListWidget(this)), key(str) {
    updateList();
    connect(list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(clicked(QListWidgetItem*)));

    QLabel* title(new QLabel("Casella di ricerca, cliccare su un libro per riceverlo", this));
    QPushButton* back(new QPushButton("Fine", this));
    back->setDefault(true);
    connect(back, SIGNAL(clicked()), this, SLOT(hide()));

    QVBoxLayout* l(new QVBoxLayout);
    l->addWidget(title);
    l->addWidget(list);
    l->addStretch();
    l->addWidget(back);

    setLayout(l);
} // SearchBox

void SearchBox::updateList() {
    list->clear();
    std::vector<int> i(b()->search(key.toStdString()));
    for (auto it : i)
        new QListWidgetItem(WGlobal::fromBook(b()->getListaLibri()->at(it)), list, it);
} // updateList

void SearchBox::clicked(QListWidgetItem* item) {
    int id(item->type());
    if (b()->daiInPrestito(id)) {
        Message msg(this, "Prestito Libri", "Libro preso in prestito, spostato nella sezione libri in prestito");
        find();
    } else
        Message msg(this, "Prestito Libri", "Errore nel prestare il libro selezionato");
    updateList();
} // clicked
