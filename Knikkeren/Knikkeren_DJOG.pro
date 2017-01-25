TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    knikker.cpp \
    bollen.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

INCLUDEPATH += C:\SFML-2.4.1\include

LIBS += -LC:/SFML-2.4.1/lib
LIBS += -LC:\SFML-2.4.1\bin
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


HEADERS += \
    window_looper.h \
    game.h \
    knikker.h \
    bollen.h
