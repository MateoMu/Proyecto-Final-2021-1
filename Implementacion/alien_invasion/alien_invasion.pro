#-------------------------------------------------
#
# Project created by QtCreator 2021-10-22T19:33:06
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alien_invasion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    escena.cpp \
    basedatos.cpp \
    movimientos.cpp \
    objetos_graficos.cpp \
    control_usuario.cpp \
    objetos_movil.cpp

HEADERS += \
        MainWindow.h \
    escena.h \
    basedatos.h \
    movimientos.h \
    objetos_graficos.h \
    control_usuario.h \
    objetos_movil.h

FORMS += \
        MainWindow.ui \
    control_usuario.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc

DISTFILES += \
    Imagenes/crear cuenta.png \
    Imagenes/nombre de la escena.png
