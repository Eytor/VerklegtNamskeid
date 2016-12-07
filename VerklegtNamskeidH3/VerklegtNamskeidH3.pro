QT += core
QT -= gui
QT += core sql
RC_FILE = myapp.rc

CONFIG += c++11

TARGET = VerklegtNamskeidH3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    domainservice.cpp \
    dataaccess.cpp

HEADERS += \
    consoleui.h \
    domainservice.h \
    dataaccess.h
