// fe/window/subwindow/searchbox.h

#ifndef SEARCHBOX_H
#define SEARCHBOX_H

// front-end
#include "../window.h"
#include "../../widget/wglobal.h"
#include "../../widget/message.h"

// Qt
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPointer>

class SearchBox : public Window {
     Q_OBJECT
private:
    QPointer<QListWidget> list;
    QString key;
private slots:
    void updateList();
    void clicked(QListWidgetItem*);
public:
    SearchBox(Biblioteca* =nullptr, const QString& ="");
signals:
    void find();
}; // SearchBox

#endif // SEARCHBOX_H
