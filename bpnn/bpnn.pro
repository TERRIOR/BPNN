QT += core
QT -= gui

CONFIG += c++11

TARGET = bpnn
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    net.cpp \
    layer.cpp \
    inputlayer.cpp \
    outputlayer.cpp \
    fclayer.cpp \
    datablock.cpp \
    datablock2.cpp \
    caculateblock.cpp \
    mytime.cpp

HEADERS += \
    net.h \
    layer.h \
    inputlayer.h \
    outputlayer.h \
    fclayer.h \
    datablock.h \
    datablock2.h \
    caculateblock.h \
    mytime.h
