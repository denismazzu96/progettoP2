// fe/windows/window

#ifndef WINDOW_H
#define WINDOW_H

// Qt
#include <QScreen>
#include <QApplication>
#include <QLayout>
#include <QDesktopWidget>

// Front-end
#include "../widget/bwidget.h"

class Window : public BWidget {
    Q_OBJECT
public:
    Window(Biblioteca* =nullptr);

    // centra la finestra al centro del desktop, di default richiamato da Window::setLayout(...)
    void autoFillGlobal();
    void setLayout(QLayout*);
signals:
    void nextWindow(Window*);
}; // Windwo

#endif // WINDOW_H
