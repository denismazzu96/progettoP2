// fe/adminframe.h

#ifndef ADMINFRAME_H
#define ADMINFRAME_H

// front-end
#include "../widget/bwidget.h"
#include "adminbox/leftuserbox.h"
#include "adminbox/rightuserbox.h"
#include "adminbox/leftbookbox.h"
#include "adminbox/rightbookbox.h"

// Qt
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

class AdminFrame : public BWidget {
    Q_OBJECT
public:
    AdminFrame(QWidget* =nullptr, Biblioteca* =nullptr);
signals:
    void updateAll();
}; // AdminFrame

#endif // ADMINFRAME_H
