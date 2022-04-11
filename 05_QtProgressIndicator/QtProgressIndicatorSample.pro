TEMPLATE = app
TARGET = QtProgressIndicatorSample

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEPENDPATH += .
INCLUDEPATH += . intermediate

# Input
HEADERS += \
    QtProgressIndicator.h
SOURCES += main.cpp \
    QtProgressIndicator.cpp

OBJECTS_DIR = intermediate
MOC_DIR = intermediate
UI_HEADERS_DIR = intermediate
UI_SOURCES_DIR = intermediate
RCC_DIR = intermediate
