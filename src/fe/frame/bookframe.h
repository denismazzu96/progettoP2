// fe/frame/bookframe.h

#ifndef BOOKFRAME_H
#define BOOKFRAME_H

// Other
#include <vector>

// Qt
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPointer>

// front-end
#include "../widget/bwidget.h"
#include "../widget/wglobal.h"
#include "../windows/subwindows/searchbox.h"
#include "../widget/message.h"

class BookFrame : public BWidget {
    Q_OBJECT
private:
    QPointer<QListWidget> libri, prestito;
    QPointer<QLineEdit> src_txt;

    void updateLibri();
    void updatePrestito();
public:
    BookFrame(QWidget* =nullptr, Biblioteca* =nullptr);
private slots:
    void update();
    void itemLibriSelected(QListWidgetItem*);
    void itemPrestitoSelected(QListWidgetItem*);

    void search();
}; // BookFrame

#endif // BOOKFRAME_H
