#-------------------------------------------------
#
# Project created by QtCreator 2013-10-23T19:31:24
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BinduProjectTeacher
TEMPLATE = app


SOURCES += main.cpp\
        teacher.cpp \
    homeworktool.cpp \
    newhomework.cpp \
    newnote.cpp \
    openhomework.cpp \
    manageclasses.cpp

HEADERS  += teacher.h \
    homeworktool.h \
    newhomework.h \
    newnote.h \
    openhomework.h \
    manageclasses.h

FORMS    += teacher.ui \
    homeworktool.ui \
    newhomework.ui \
    newnote.ui \
    openhomework.ui \
    manageclasses.ui
