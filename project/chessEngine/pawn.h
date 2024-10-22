#ifndef PAWN_H
#define PAWN_H
#include "QString"

#include "piece.h"

class Pawn : public Piece
{
    public:
        Pawn(PieceColor pieceColor,Field& field);
        QString toText() {
            return "P";
        }

    private:
        QList<PieceMove*> pieceMoves();
};

#endif // PAWN_H
