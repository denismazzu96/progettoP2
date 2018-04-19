// fe/window/regwindow.h

#ifndef REGWINDOW_H
#define REGWINDOW_H

// front-end
#include "window.h"
#include "infowindow.h"
#include "loginwindow.h"
#include "../widget/userform.h"

class RegWindow : public Window {
    Q_OBJECT
public:
    RegWindow(Biblioteca* =nullptr);
private slots:
    void registra(Obj*);
    void indietro(); // pulsante indietro
}; // RegWindo

#endif // REGWINDOW_H
