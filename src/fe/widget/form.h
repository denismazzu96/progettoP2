// fe/widget/form.h

#ifndef FORM_H
#define FORM_H

// Qt
#include <QWidget>

// back-end
#include "../../be/contenitore/obj.h"

class Form : public QWidget {
    Q_OBJECT
public:
    Form(QWidget* =nullptr);

signals:
    void clicked(Obj*);
}; // Form

#endif // FORM_H
