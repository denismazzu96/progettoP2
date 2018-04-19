#include "bookframe.h"

BookFrame::BookFrame(QWidget *parent, Biblioteca *biblioteca) : BWidget(parent, biblioteca), libri(new QListWidget(this)), prestito(new QListWidget(this)), src_txt(new QLineEdit(this)) {

    libri->setMidLineWidth(WGlobal::MIN_BOX);
    prestito->setMinimumWidth(WGlobal::MIN_BOX);
    // Book Tab Box
    QTabWidget* tab(new QTabWidget(this));
    updateLibri();
    updatePrestito();
    tab->addTab(libri, "Lista Libri");
    tab->addTab(prestito, "Libri in Prestito");

    QLabel* src_lbl(new QLabel("Barra di Ricerca:", this));
    QPushButton* src_btn(new QPushButton("Cerca", this));
    src_btn->setAutoDefault(true);
    setTabOrder(src_txt, src_btn);
    QHBoxLayout* src_l(new QHBoxLayout);
    src_l->addWidget(src_txt);
    src_l->addWidget(src_btn);
    connect(src_btn, SIGNAL(clicked()), this, SLOT(search()));

    QBoxLayout* l(new QVBoxLayout);
    l->addWidget(tab);
    l->addWidget(src_lbl);
    l->addLayout(src_l);
    setLayout(l);

    connect(libri, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(itemLibriSelected(QListWidgetItem*)));
    connect(prestito, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(itemPrestitoSelected(QListWidgetItem*)));
    update();
} // BookFrame

void BookFrame::updateLibri() {
    libri->clear();
    int i(0);
    for (auto it : *(b()->getListaLibri()))
        new QListWidgetItem(WGlobal::fromBook(it), libri, i++);
} // updateLibri

void BookFrame::updatePrestito() {
    prestito->clear();
    int i(0);
    for (auto it : *(b()->getUtente()->getLista()))
        new QListWidgetItem(WGlobal::fromBook(it), prestito, i++);
} // updatePrestito

void BookFrame::update() {
    updateLibri();
    updatePrestito();
    BWidget::update();
} // updateAll

void BookFrame::itemLibriSelected(QListWidgetItem* item) {
    int id(item->type());
    if (b()->daiInPrestito(id)) {
        update();
        Message msg(this, "Prestito Libri", "Libro preso in prestito, spostato nela sezione libri in prestito");
    } else
        Message msg(this, "Prestito Libri", "Errore nel prestare il libro");
} // itemLibriSelected

void BookFrame::itemPrestitoSelected(QListWidgetItem* item) {
    int id(item->type());
    b()->restituisci(b()->getUtente()->getLista()->at(id));
    update();
    Message msg(this, "Prestito Libri", "Libro restituito, spostato nella sezione lista libri");
} // itemLibriSelected

void BookFrame::search() {
    SearchBox* sbox(new SearchBox(b(), src_txt->text()));
    sbox->show();
    connect(sbox, SIGNAL(find()), this, SLOT(update()));
} // search
