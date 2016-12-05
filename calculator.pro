#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T16:37:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app


SOURCES += main.cpp\
    unary_operation.cpp \
    binary_operator.cpp \
    constant.cpp \
    basic_operation.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc
