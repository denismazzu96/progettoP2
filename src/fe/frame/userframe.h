// fe/frame/userframe

#ifndef USERFRAME_H
#define USERFRAME_H

// front-end
#include "../widget/bwidget.h"
#include "../windows/subwindows/setuserdata.h"

// Qt
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCoreApplication>
#include <QPointer>

class UserFrame : public BWidget{
    Q_OBJECT
private:
    QPointer<QLabel> no_lbl, co_lbl;
public:
    UserFrame(QWidget* =nullptr, Biblioteca* =nullptr);
private slots:
    void logout();
    void restituisciAll();
    void deleteMe();
    void modifica();
    void updateInfo();
signals:
    void updateAll();
}; // UserFrame

#endif // USERFRAME_H
