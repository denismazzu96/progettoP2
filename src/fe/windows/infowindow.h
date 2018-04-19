// fe/windows/infowindow.h

#ifndef INFOWINDOW_H
#define INFOWINDOW_H

// front-end
#include "window.h"
#include "mainwindow.h"

// Qt
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QTimer>
#include <QPointer>
#include <QVector>

class InfoWindow : public Window {
    Q_OBJECT
private:
    QPointer<QProgressBar> pb;
    QPointer<QTimer> timer;
    int max;

private slots:
    void updatePB();
public:
    InfoWindow(Biblioteca* =nullptr);

    void keyPressEvent(QKeyEvent*);
}; // InfoWindow

#endif // INFOWINDOW_H
