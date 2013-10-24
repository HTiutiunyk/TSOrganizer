#-------------------------------------------------
#
# Project created by QtCreator 2013-10-17T20:06:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = TSOrganizer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    newtaskwindow.cpp \
    settingspage.cpp

HEADERS  += mainwindow.h \
    database.h \
    newtaskwindow.h \
    settingspage.h

FORMS    += mainwindow.ui \
    newtaskwindow.ui \
    settingspage.ui
