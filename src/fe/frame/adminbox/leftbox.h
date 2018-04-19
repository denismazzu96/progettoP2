// fe/frame/adminbox/leftbox.h

#ifndef LEFTBOX_H
#define LEFTBOX_H

// front-end
#include "../../widget/bwidget.h"
#include "../../widget/wglobal.h"

// Qt
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QPointer>

class LeftBox : public BWidget {
    Q_OBJECT
private:
    QPointer<QListWidget> list;
protected:
    QListWidget* getList() const;
protected slots:
    virtual void deleteAll() =0;
    virtual void deleteItem(QListWidgetItem*) =0;

public:
    LeftBox(QWidget* =nullptr, Biblioteca* =nullptr, const QString& ="");
public slots:
    virtual void updateList() =0;
}; // LeftBox

#endif // LEFTBOX_H
