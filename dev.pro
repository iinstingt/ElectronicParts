#-------------------------------------------------
#
# Project created by QtCreator 2013-07-18T19:13:41
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dev
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        database.cpp \
    tree.cpp

HEADERS  += mainwindow.h \
            database.h \
    tree.h

FORMS    += mainwindow.ui

RESOURCES += \
    resurces.qrc
