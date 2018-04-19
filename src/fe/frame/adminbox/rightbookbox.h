// fe/frame/adminbox/rightbookbox.h

#ifndef RIGHTBOOKBOX_H
#define RIGHTBOOKBOX_H

// front-end
#include "rightbox.h"
#include "../../widget/bookform.h"
#include "../../widget/message.h"

class RightBookBox : public RightBox {
    Q_OBJECT
public:
    RightBookBox(QWidget* =nullptr, Biblioteca* =nullptr);
private slots:
    void setItem(Obj*); // puntatore -> LibroMod
}; // RightBookBox

#endif // RIGHTBOOKBOX_H
