// fe/applicationcore.h

#ifndef APPLICATIONCORE_H
#define APPLICATIONCORE_H

// back-end
#include "../be/biblioteca.h"

// front-end
#include "windows/window.h"
#include "windows/loginwindow.h"

// Qt
#include <QCoreApplication>
#include <QObject>
#include <QPointer>

// Other

class ApplicationCore : public QObject{
    Q_OBJECT
private:
    Biblioteca b;
    QPointer<Window> window;
public:
    ApplicationCore();
    ~ApplicationCore();
public slots:
    void windowChanged(Window*);
}; // ApplicationCore

#endif // APPLICATIONCORE_H
