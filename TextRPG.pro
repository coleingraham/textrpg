TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /Users/coledingraham/Sources/jsoncpp/trunk/jsoncpp/include/json

LIBS += /Users/coledingraham/Sources/jsoncpp/trunk/jsoncpp/buildscons/linux-gcc-4.2.1/src/lib_json/libjson_linux-gcc-4.2.1_libmt.a

SOURCES += main.cpp

HEADERS += \
    TerminalFormatting.h

