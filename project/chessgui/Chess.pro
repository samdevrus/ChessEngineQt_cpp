#-------------------------------------------------
#
# Project created by QtCreator 2012-03-21T22:01:54
#
#-------------------------------------------------

QT       += core gui

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
    tile.cpp \
    validation.cpp \
    ../chessEngine/rockmovement.cpp \
    ../chessEngine/rock.cpp \
    ../chessEngine/queen.cpp \
    ../chessEngine/positionanalyserv1.cpp \
    ../chessEngine/pawn.cpp \
    ../chessEngine/pawnmovement.cpp \
    ../chessEngine/piece.cpp \
    ../chessEngine/piecemove.cpp \
    ../chessEngine/piecemovement.cpp \
    ../chessEngine/knightmovement.cpp \
    ../chessEngine/knight.cpp \
    ../chessEngine/kingmovement.cpp \
    ../chessEngine/king.cpp \
    ../chessEngine/field.cpp \
    ../chessEngine/board.cpp \
    ../chessEngine/bishopmovement.cpp \
    ../chessEngine/bishop.cpp \
    movemake.cpp

HEADERS  += \
    tile.h \
    validation.h \
    ../chessEngine/rockmovement.h \
    ../chessEngine/rock.h \
    ../chessEngine/queen.h \
    ../chessEngine/positionanalyserv1.h \
    ../chessEngine/moveinfo.h \
    ../chessEngine/pawn.h \
    ../chessEngine/pawnmovement.h \
    ../chessEngine/piece.h \
    ../chessEngine/piecemove.h \
    ../chessEngine/piecemovement.h \
    ../chessEngine/knightmovement.h \
    ../chessEngine/knight.h \
    ../chessEngine/kingmovement.h \
    ../chessEngine/king.h \
    ../chessEngine/ipositionanalyser.h \
    ../chessEngine/ifieldmanager.h \
    ../chessEngine/field.h \
    ../chessEngine/chessbase.h \
    ../chessEngine/board.h \
    ../chessEngine/bishopmovement.h \
    ../chessEngine/bishop.h \
    movemake.h

FORMS    +=

RESOURCES += \
    Images.qrc
