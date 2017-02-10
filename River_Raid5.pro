#-------------------------------------------------
#
# Project created by QtCreator 2017-01-31T21:34:12
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = River_Raid5
TEMPLATE = app


SOURCES += main.cpp \
    viewmain.cpp \
    scenemain.cpp \
    fighter.cpp \
    bullet.cpp \
    obstacle.cpp \
    helicopter.cpp \
    ship.cpp \
    jet.cpp \
    land.cpp \
    fueltank.cpp \
    gate.cpp \
    mapdrawer.cpp \
    explosion.cpp \
    firstbutton.cpp \
    game.cpp \
    score.cpp \
    fuel.cpp

HEADERS  += \
    viewmain.h \
    fighter.h \
    bullet.h \
    obstacle.h \
    helicopter.h \
    ship.h \
    jet.h \
    land.h \
    fueltank.h \
    gate.h \
    scenemain.h \
    mapdrawer.h \
    explosion.h \
    firstbutton.h \
    game.h \
    score.h \
    fuel.h

FORMS    +=

RESOURCES += \
    res.qrc
