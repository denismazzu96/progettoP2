// fe/strumenti/bwidget.h

// classe che serve a gestire un QWidget collegato alla biblioteca

#ifndef BWIDGET_H
#define BWIDGET_H

// Qt
#include <QWidget>

// Back-end
#include "../../be/biblioteca.h"

class BWidget : public QWidget {
    Q_OBJECT
private:
    Biblioteca* biblioteca;
public:
    BWidget(QWidget* =nullptr, Biblioteca* =nullptr);
    // non serve ridefinire la rule-of-three perchè la Biblioteca è un oggetto in ApplicationCore
    // a lui è demandato il compito di occuparsene

    Biblioteca* b();
}; // BWidget

#endif // BWIDGET_H
