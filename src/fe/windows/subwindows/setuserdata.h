// fe/windows/subwindows/setuserdata.h

#ifndef SETUSERDATA_H
#define SETUSERDATA_H

// front-end
#include "../window.h"

// Qt
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPointer>

class SetUserData : public Window {
    Q_OBJECT
private:
    QPointer<QLineEdit> no_txt, co_txt;
public:
    SetUserData(Biblioteca* =nullptr);
signals:
    void updateAll();
private slots:
    void set();
}; // SetUserData

#endif // SETUSERDATA_H
