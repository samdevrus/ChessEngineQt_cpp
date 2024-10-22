#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
    public:
        Bishop(PieceColor pieceColor,Field& field,IFieldManager* fieldManager);
        QString toText() {
            return "B";
        }
    private:
        QList<PieceMove*> pieceMoves();
};

#endif // BISHOP_H
