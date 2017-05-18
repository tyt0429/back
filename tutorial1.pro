#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T21:53:37
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tutorial1
TEMPLATE = app


SOURCES += main.cpp \
    MyRect.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    mytower.cpp \
    enemytower.cpp

HEADERS  += \
    MyRect.h \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    health.h \
    mytower.h \
    enemytower.h

FORMS    +=

RESOURCES +=
