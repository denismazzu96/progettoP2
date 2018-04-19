// fe/windows/loginwindow.h

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

// front-end
#include "window.h"
#include "infowindow.h" // prossima finestra
#include "regwindow.h" // finestra registrazione

// back-end
#include "../../be/biblioteca.h"

// Qt
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QPointer>

class LoginWindow : public Window {
    Q_OBJECT
private:
    QPointer<QLineEdit> user_txt, psw_txt;
public:
    LoginWindow(Biblioteca* =nullptr);
public slots:
    void login();
    void registra();
}; // LoginWindow

#endif // LOGINWINDOW_H
