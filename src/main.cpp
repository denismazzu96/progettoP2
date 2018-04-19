// main.cpp

#include <QApplication>
#include "fe/applicationcore.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icons/icon.ico"));
    ApplicationCore ac;

    return app.exec();
} // main
