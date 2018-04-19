// fe/widget/message.h)

#ifndef MESSAGE_H
#define MESSAGE_H

// Qt
#include <QMessageBox>

class Message {
public:
    Message(QWidget* =nullptr, const QString& ="Titolo", const QString& ="Contenuto");
}; // Message

#endif // MESSAGE_H
