#-------------------------------------------------
#
# Project created by QtCreator 2013-11-28T10:13:03
#
#-------------------------------------------------

QT       += core

QT       -= gui
#MA
#QKE_CXXFLAGS +=-std=gnu++11


TARGET = chessEngine
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    board.cpp \
    piece.cpp \
    square.cpp \
    pawn.cpp \
    piecemove.cpp \
    field.cpp \
    piecemovement.cpp \
    pawnmovement.cpp \
    rockmovement.cpp \
    rock.cpp \
    bishopmovement.cpp \
    bishop.cpp

HEADERS += \
    board.h \
    piece.h \
    square.h \
    pawn.h \
    piecemove.h \
    field.h \
    piecemovement.h \
    chessbase.h \
    pawnmovement.h \
    moveinfo.h \
    rockmovement.h \
    ifieldmanager.h \
    rock.h \
    bishopmovement.h \
    bishop.h

