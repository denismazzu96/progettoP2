#-------------------------------------------------
#
# Project created by QtCreator 2017-08-11T16:57:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# param
CONFIG += c++11
# end

TARGET = Biblioteca
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050501    # disables all the APIs deprecated before Qt 5.5.1

SOURCES += main.cpp\
    be/contenitore/libro.cpp \
    be/contenitore/libromod.cpp \
    be/eccezioni/bad_admin.cpp \
    be/strumenti/global.cpp \
    be/utenti/admin.cpp \
    be/utenti/persona.cpp \
    be/utenti/utente.cpp \
    be/utenti/utenteavanzato.cpp \
    be/biblioteca.cpp \
    fe/applicationcore.cpp \
    fe/windows/window.cpp \
    fe/windows/loginwindow.cpp \
    fe/windows/mainwindow.cpp \
    be/eccezioni/bibl_expected.cpp \
    fe/windows/regwindow.cpp \
    fe/frame/userframe.cpp \
    fe/frame/bookframe.cpp \
    fe/widget/bwidget.cpp \
    fe/frame/adminframe.cpp \
    fe/widget/userform.cpp \
    fe/windows/infowindow.cpp \
    fe/frame/adminbox/leftuserbox.cpp \
    fe/frame/adminbox/rightuserbox.cpp \
    fe/frame/adminbox/leftbox.cpp \
    fe/frame/adminbox/leftbookbox.cpp \
    fe/widget/form.cpp \
    fe/frame/adminbox/rightbox.cpp \
    fe/frame/adminbox/rightbookbox.cpp \
    fe/widget/bookform.cpp \
    fe/widget/message.cpp \
    fe/widget/wglobal.cpp \
    fe/windows/subwindows/searchbox.cpp \
    fe/windows/subwindows/setbookdata.cpp \
    fe/windows/subwindows/setuserdata.cpp \
    be/contenitore/attributilibro.cpp \
    be/contenitore/contenitoreutenti.cpp \
    be/contenitore/contenitore.cpp

HEADERS  += \
    be/contenitore/contenitore.h \
    be/contenitore/libro.h \
    be/contenitore/libromod.h \
    be/eccezioni/bad_admin.h \
    be/strumenti/global.h \
    be/utenti/admin.h \
    be/utenti/persona.h \
    be/utenti/utente.h \
    be/utenti/utenteavanzato.h \
    be/biblioteca.h \
    fe/applicationcore.h \
    fe/windows/loginwindow.h \
    fe/windows/window.h \
    fe/windows/mainwindow.h \
    be/eccezioni/bibl_expected.h \
    fe/windows/regwindow.h \
    fe/frame/userframe.h \
    fe/frame/bookframe.h \
    fe/widget/bwidget.h \
    fe/frame/adminframe.h \
    fe/widget/userform.h \
    fe/windows/infowindow.h \
    fe/frame/adminbox/leftuserbox.h \
    fe/frame/adminbox/rightuserbox.h \
    fe/frame/adminbox/leftbookbox.h \
    fe/frame/adminbox/leftbox.h \
    fe/widget/form.h \
    fe/frame/adminbox/rightbox.h \
    fe/frame/adminbox/rightbookbox.h \
    fe/widget/bookform.h \
    fe/widget/message.h \
    fe/widget/wglobal.h \
    fe/windows/subwindows/searchbox.h \
    fe/windows/subwindows/setbookdata.h \
    fe/windows/subwindows/setuserdata.h \
    be/contenitore/attributilibro.h \
    be/contenitore/contenitoreutenti.h \
    be/contenitore/contenitorebase.h \
    be/contenitore/obj.h

RESOURCES += \
    resource.qrc
