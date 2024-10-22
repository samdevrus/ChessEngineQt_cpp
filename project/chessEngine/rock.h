#ifndef ROCK_H
#define ROCK_H
#include "piece.h"

class Rock : public Piece
{
    public:
        Rock(PieceColor pieceColor,Field& field,IFieldManager* fieldManager);
        QString toText() {
            return "R";
        }
    private:
        QList<PieceMove*> pieceMoves();
};

#endif // ROCK_H
