#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T14:02:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MST
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    Delaunay.cpp \
    basecalculate.cpp \
    dialog.cpp \
    ShowScene.cpp \
    QGraphicsItemPoint.cpp \
    ShowView.cpp

HEADERS  += mainwindow.h \
    Delaunay.h \
    basecalculate.h \
    dialog.h \
    ShowScene.h \
    QGraphicsItemPoint.h \
    ShowView.h

FORMS    += mainwindow.ui \
    dialog.ui
