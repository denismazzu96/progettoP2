#include "window.h"

Window::Window(Biblioteca *b) : BWidget(nullptr, b) {} // Window

void Window::autoFillGlobal() {
    adjustSize();
    int x((QApplication::desktop()->screen()->rect().width()-width())/2),
            y((QApplication::desktop()->screen()->rect().height()-height())/2);
    move(x, y);
} // autoFillGlobal

void Window::setLayout(QLayout *l) {
    BWidget::setLayout(l);
    autoFillGlobal();
} // setLayout
