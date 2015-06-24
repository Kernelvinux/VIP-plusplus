#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T13:07:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = vipp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    featuresVIP.cpp \
    filters.cpp \
    object.cpp \
    ntva.cpp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv

HEADERS += \
    filters.h \
    main.h \
    featuresVIP.h \
    object.h \
    ntva.h
