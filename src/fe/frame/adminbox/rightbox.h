// fe/frame/adminbox/rightbox.h

#ifndef RIGHTBOX_H
#define RIGHTBOX_H

// Qt
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>

// front-end
#include "../../widget/bwidget.h"
#include "../../widget/form.h"
#include "../../widget/wglobal.h"

class RightBox : public BWidget {
    Q_OBJECT
public:
    RightBox(QWidget* =nullptr, Biblioteca* =nullptr, const QString& ="", Form* =nullptr);
signals:
    void updateAll();
protected slots:
    virtual void setItem(Obj*) =0;
}; // RightBox

#endif // RIGHTBOX_H
