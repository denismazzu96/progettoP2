#include "adminframe.h"

AdminFrame::AdminFrame(QWidget *parent, Biblioteca *biblioteca) : BWidget(parent, biblioteca) {
    LeftBox *lu_box(new LeftUserBox(this, b())),
            *lb_box(new LeftBookBox(this, b()));
    RightBox *ru_box(new RightUserBox(this, b())),
            *rb_box(new RightBookBox(this, b()));
    QHBoxLayout* gbu_l(new QHBoxLayout),
            *gbb_l(new QHBoxLayout);
    gbu_l->addWidget(lu_box);
    gbu_l->addWidget(ru_box);
    gbb_l->addWidget(lb_box);
    gbb_l->addWidget(rb_box);

    QGroupBox *gbu(new QGroupBox("User Settings", this));
    gbu->setLayout(gbu_l);
    QGroupBox *gbb(new QGroupBox("Book Settings", this));
    gbb->setLayout(gbb_l);

    QVBoxLayout* l(new QVBoxLayout);
    l->addWidget(gbu);
    l->addStretch(0);
    l->addWidget(gbb);
    setLayout(l);

    connect(ru_box, SIGNAL(updateAll()), lu_box, SLOT(updateList()));
    connect(rb_box, SIGNAL(updateAll()), lb_box, SLOT(updateList()));
    connect(rb_box, SIGNAL(updateAll()), this, SIGNAL(updateAll()));
    connect(lb_box, SIGNAL(updateAll()), this, SIGNAL(updateAll()));
} // AdminFrame
