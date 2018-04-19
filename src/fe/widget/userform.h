#ifndef USERFORM_H
#define USERFORM_H

// back-end
#include "../../be/utenti/admin.h"

// Qt
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPointer>

// front-end
#include "form.h"

class UserForm : public Form {
    Q_OBJECT
private:
    QPointer<QLineEdit> us_txt, ps_txt, no_txt, co_txt, gr_txt, cn_txt; // username, password, nome, cognome, grado(può esere vuoto -> Utente)
    bool type;
public:
    UserForm(QWidget* =nullptr, const QString& ="Registrati", bool =true);
    // il bool serve a specificare se serve la label/textedit per il grado

private slots:
    void _clicked();
}; // UserForm

#endif // USERFORM_H
