#include "mainwindow.h"

MainWindow::MainWindow(Biblioteca *biblioteca) : Window(biblioteca) {
    UserFrame *user_div(new UserFrame(this, b()));
    BookFrame *book_div(new BookFrame(this, b()));

    auto line1(new QFrame(this)), line2(new QFrame(this)); // linee di separazione
    line1->setFrameShape(QFrame::VLine);
    line2->setFrameShape(QFrame::VLine);

    QHBoxLayout *l(new QHBoxLayout);
    l->addWidget(user_div);
    l->addWidget(line1);
    l->addWidget(book_div);
    if (b()->getUtente()->isAdmin()) {
        l->addWidget(line2);
        AdminFrame*admin_div(new AdminFrame(this, b()));
        l->addWidget(admin_div);
        connect(admin_div, SIGNAL(updateAll()), book_div, SLOT(update()));
    } else
        line2->hide();

    setLayout(l);

    connect(user_div, SIGNAL(updateAll()), book_div, SLOT(update()));
} // MainWindow
