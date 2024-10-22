#ifndef FIELD_H
#define FIELD_H
#define NULL 0
#include "QDebug"
#include "chessbase.h"

class Piece;

class Field
{
    public:
        Field(FieldCoordinate coordinate,Piece* piece = NULL);

        bool isEmpty() {
            return piece == NULL;
        }
        Piece* removePiece() {
            Piece* p = this->piece;
            this->piece = NULL;
           // qDebug()<<(int)coordinate.x;
            return p;
        }
        Piece* getPiece() {
            return piece;
        }
        Piece& setPiece(Piece& piece) {
            this->piece = &piece;
            //qDebug()<<(int)coordinate.x;
            return piece;
        }
        FieldCoordinate& getCoordinate() {
            //qDebug()<<(int)coordinate.x;
            return coordinate;
        }

    protected:
        FieldCoordinate coordinate;
        Piece* piece;
};

#endif // FIELD_H
