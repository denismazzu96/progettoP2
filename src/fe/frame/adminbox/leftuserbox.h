// fe/frame/adminbox/leftuserbox.h

#ifndef LEFTUSERBOX_H
#define LEFTUSERBOX_H

// front-end
#include "leftbox.h"
#include "../../widget/wglobal.h"
#include "../../widget/message.h"

// Qt
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class LeftUserBox : public LeftBox {
    Q_OBJECT
public slots:
    void updateList();
protected slots:
    void deleteAll();
    void deleteItem(QListWidgetItem*);

public:
    LeftUserBox(QWidget* =nullptr, Biblioteca* =nullptr);
}; // LeftUserBox

#endif // LEFTUSERBOX_H
