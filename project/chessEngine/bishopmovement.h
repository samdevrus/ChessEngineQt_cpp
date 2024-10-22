#ifndef BISHOPMOVEMENT_H
#define BISHOPMOVEMENT_H
#include "piecemovement.h"

class BishopMovement : public PieceMovement
{
    public:
        BishopMovement(FieldCoordinate coordinate);
        PieceMove* DownLeft();
        PieceMove* UpLeft();
        PieceMove* DownRight();
        PieceMove* UpRight();
    private:
        FieldCoordinate dlc,ulc,drc,urc;

};

#endif // BISHOPMOVEMENT_H
