#ifndef PIECE_H
#define PIECE_H
#include "QList"

#include "field.h"
#include "piecemove.h"
#include "ifieldmanager.h"

class Piece
{
    public:
        Piece(PieceColor pieceColor,Field& field);
        QList<PieceMove*> getPieceMoves() {
            return pieceMoves();
        }
        PieceColor getColor() {
            return color;
        }
        Field& getField() {
            return *currentField;
        }

        void move() {
            moved++;
        }
        void unmove() {
            moved--;
        }

        bool isMoved() {
            return moved>0;
        }

        virtual QString toText() = 0;
        void setField(Field* field) {
            currentField = field;
        }
        PieceType getType() {
            return type;
        }
    protected:
        virtual QList<PieceMove*> pieceMoves() = 0;
        PieceColor color;
        PieceType type;
        int moved;
        Field* currentField;
        IFieldManager* fieldManager;
};

#endif // PIECE_H
