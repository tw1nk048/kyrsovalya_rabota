#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T09:49:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoveGraphicsItem
TEMPLATE = app


SOURCES += main.cpp\
    line.cpp \
    loadFile.cpp \
    movecash.cpp \
    movetable.cpp \
    saveFile.cpp \
        widget.cpp \
    moveitem.cpp \
    scene.cpp \

HEADERS  += widget.h \
    line.h \
    loadFile.h \
    movecash.h \
    moveitem.h \
    movetable.h \
    saveFile.h \
    scene.h \

FORMS    += widget.ui

RESOURCES += \
    images.qrc
