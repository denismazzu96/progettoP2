// fe/frame/adminbox/leftbookbox.h

#ifndef LEFTBOOKBOX_H
#define LEFTBOOKBOX_H

// front-end
#include "leftbox.h"
#include "../../widget/wglobal.h"
#include "../../widget/message.h"
#include "../../windows/subwindows/setbookdata.h"

// Qt
#include <QMessageBox>

class LeftBookBox : public LeftBox {
    Q_OBJECT
public slots:
    void updateList();
protected slots:
    void deleteAll();
    void deleteItem(QListWidgetItem*);
signals:
    void updateAll();
public:
    LeftBookBox(QWidget* =nullptr, Biblioteca* =nullptr);
}; // LeftBookBox

#endif // LEFTBOOKBOX_H
