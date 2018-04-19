// fe/fram/adminbox/rightuserbox.h

#ifndef RIGHTUSERBOX_H
#define RIGHTUSERBOX_H

// front-end
#include "rightbox.h"
#include "../../widget/userform.h"

// Qt
#include <QVBoxLayout>
#include <QGroupBox>

class RightUserBox : public RightBox {
    Q_OBJECT
public:
    RightUserBox(QWidget* =nullptr, Biblioteca* =nullptr);
private slots:
    void setItem(Obj *); // puntatore -> Utente
}; // RightUserBox

#endif // RIGHTUSERBOX_H
