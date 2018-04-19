// fe/windows/subwindow/setbookdata.h

#ifndef SETBOOKDATAA_H
#define SETBOOKDATAA_H

// front-end
#include "../window.h"
#include "../../widget/bookform.h"
#include "../../widget/message.h"

// Qt
#include <QPointer>
#include <QVBoxLayout>
#include <QPushButton>

class SetBookData : public Window {
    Q_OBJECT
private:
    QPointer<BookForm> form;
    int id;
public:
    SetBookData(Biblioteca* =nullptr, int =0);
private slots:
    void set(Obj*);
signals:
    void updateAll();
}; // SetBookData
#endif // SETBOOKDATAA_H
