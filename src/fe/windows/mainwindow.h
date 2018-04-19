// fe/windows/mainwindow

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// front-end
#include "window.h"
#include "../frame/userframe.h"
#include "../frame/bookframe.h"
#include "../frame/adminframe.h"

// Qt
#include <QFrame>
#include <QHBoxLayout>

class MainWindow : public Window {
    Q_OBJECT
public:
    MainWindow(Biblioteca* =nullptr);
}; // MainWindow

#endif // MAINWINDOW_H
