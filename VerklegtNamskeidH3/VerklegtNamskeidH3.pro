#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T18:02:31
#
#-------------------------------------------------

QT       += core gui
QT += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VerklegtNamskeidH3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    domainservice.cpp \
    dataaccess.cpp

HEADERS  += mainwindow.h \
    domainservice.h \
    dataaccess.h

FORMS    += mainwindow.ui
