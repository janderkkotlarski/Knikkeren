TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    balls.cpp \
    marble.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

INCLUDEPATH += D:/SFML-2.4.0/include

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
LIBS += -LD:/SFML-2.4.0/lib
LIBS += -LD:\SFML-2.4.0\bin

HEADERS += \
    game.h \
    balls.h \
    marble.h
