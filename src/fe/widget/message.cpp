#include "message.h"

Message::Message(QWidget *parent, const QString &title, const QString &ctx) {
    QMessageBox msg(parent);
    msg.setText(title);
    msg.setInformativeText(ctx);
    msg.exec();
} // Message
