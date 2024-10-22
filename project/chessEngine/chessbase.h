#ifndef CHESSBASE_H
#define CHESSBASE_H
#include "QString";

const char SQUARE_SIDE = 8;

enum PieceColor{
    WHITE,
    BLACK
};

enum PieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROCK,
    QUEEN,
    KING
};

struct FieldCoordinate {
    FieldCoordinate() {
        this->x = 0;
        this->y = 0;
    }

    FieldCoordinate(char x, char y) {
        this->x = x;
        this->y = y;
    }
    QString toText() {
        return QString('a'+x-1)+QString::number(y);
    }

    bool isValid() {
        return x>0&&x<=SQUARE_SIDE&&y>0&&y<=SQUARE_SIDE;
    }
    FieldCoordinate up(char inc = 1) {
        return FieldCoordinate(x,y+inc);
    }
    FieldCoordinate down(char dec = 1) {
        return FieldCoordinate(x,y-dec);
    }
    FieldCoordinate left() {
        return FieldCoordinate(x-1,y);
    }
    FieldCoordinate right() {
        return FieldCoordinate(x+1,y);
    }
    FieldCoordinate upLeft() {
        return FieldCoordinate(x-1,y+1);
    }
    FieldCoordinate upRight() {
        return FieldCoordinate(x+1,y+1);
    }
    FieldCoordinate downLeft() {
        return FieldCoordinate(x-1,y-1);
    }
    FieldCoordinate downRight() {
        return FieldCoordinate(x+1,y-1);
    }
    bool operator==(const FieldCoordinate& lhs) {
        return lhs.x == x && lhs.y == y;
    }
    char x,y;
};


#endif // CHESSBASE_H
