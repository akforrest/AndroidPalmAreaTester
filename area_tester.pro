#-------------------------------------------------
#
# Project created by QtCreator 2015-09-22T14:22:59
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = touch_detection
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    view.cpp

HEADERS  += mainwindow.h \
    scene.h \
    view.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

