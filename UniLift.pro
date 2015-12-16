#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T19:36:07
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UniLift
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Elevator.cpp

HEADERS  += mainwindow.h \
    Elevator.h

FORMS    += mainwindow.ui
