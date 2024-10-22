#ifndef PAWNMOVEMENT_H
#define PAWNMOVEMENT_H
#include "QList"
#include "piecemovement.h"
#include "piecemove.h"


class PawnMovement : public PieceMovement
{
    public:
        PawnMovement(FieldCoordinate coordinate,PieceColor color);
        QList<PieceMove*> moveOneField();
        QList<PieceMove*> moveTwoField();
        QList<PieceMove*> attack();

    protected:
        PieceColor color;
};

#endif // PAWNMOVEMENT_H
