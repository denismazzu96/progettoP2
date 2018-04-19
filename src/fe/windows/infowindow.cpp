#include "infowindow.h"

InfoWindow::InfoWindow(Biblioteca *biblioteca) : Window(biblioteca), pb(new QProgressBar(this)), timer(new QTimer(this)), max(5000) {
    QVBoxLayout *l(new QVBoxLayout);

    QVector<QLabel*> info({
                              new QLabel("Finestra Informativa", this),
                              new QLabel("Premere su un libro per prenderlo in prestito o per restituirlo", this),
                              new QLabel("La ricerca viene effettuata su titolo e autore per un match completo", this),
                              new QLabel("* per un'Utente Avanzato anche per match incompleti su tutti i campi di un libro", this),
                              new QLabel("/ premere su un utente per eliminarlo", this),
                              new QLabel("/ premere su un libro per modificarlo o rimuoverlo", this),
                              new QLabel("/ se si modifica o rimuove un libro gli effetti sul Frame Utente verranno aggiornati al prossimo riavvio", this)
                          });
    bool is_a(b()->getUtente()->isAdmin()), is_ua(b()->getUtente()->isUtenteAvanzato());
    if (is_a)
        max *= 2;
    else if (is_ua)
        max *= 1.5;
    pb->setMaximum(max);

    for (auto it : info)
        if (it->text().at(0) == '/' && is_a)
            l->addWidget(it);
        else if (it->text().at(0) == '*' && is_ua)
            l->addWidget(it);
        else if (it->text().at(0) != '/' && it->text().at(0) != '*')
            l->addWidget(it);
        else it->hide();
    l->addWidget(pb);

    connect(timer, SIGNAL(timeout()), this, SLOT(updatePB()));
    timer->start(1);

    setLayout(l);
} // InfoWindow

void InfoWindow::updatePB() {
    if (max > 0) {
        max--;
        pb->setValue(pb->maximum()-max);
    } else
        keyPressEvent(nullptr);
} // updatePB

void InfoWindow::keyPressEvent(QKeyEvent *) {
    timer->stop();
    nextWindow(new MainWindow(b()));
} // KeyPressEvent
