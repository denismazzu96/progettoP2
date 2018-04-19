#include "applicationcore.h"

ApplicationCore::ApplicationCore() { // default per entrambi i parametri
    QCoreApplication::setApplicationName("Biblioteca");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    windowChanged(new LoginWindow(&b));
} // ApplicationCore

ApplicationCore::~ApplicationCore() {
    b.logout();
} // ApplicationCore

// slots:
void ApplicationCore::windowChanged(Window *newWindow) {
    if (window) window->close();
    window = newWindow; // QPointer::window
    connect(window, SIGNAL(nextWindow(Window*)), this, SLOT(windowChanged(Window*)));
    window->show();
} // windowChanged
