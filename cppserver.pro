TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tcpserver.cpp \
    clientsocket.cpp


CONFIG +=c++11

HEADERS += \
    tcpserver.h \
    clientsocket.h
