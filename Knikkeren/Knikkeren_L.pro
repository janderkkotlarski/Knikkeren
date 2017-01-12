TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    knikker.cpp \
    game.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

INCLUDEPATH += D:/SFML-2.4.0/include

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
LIBS += -LD:/SFML-2.4.0/lib
LIBS += -LD:\SFML-2.4.0\bin

HEADERS += \
    knikker.h \
    game.h
