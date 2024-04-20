QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT +=widgets
TARGET = demo
TEMPLATE = app

SOURCES += \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialog.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    mainwindow.ui

