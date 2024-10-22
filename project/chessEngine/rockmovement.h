#ifndef ROCKMOVEMENT_H
#define ROCKMOVEMENT_H
#include "piecemovement.h"

class RockMovement : public PieceMovement
{
    public:
        RockMovement(FieldCoordinate coordinate);
        PieceMove* Down();
        PieceMove* Up();
        PieceMove* Left();
        PieceMove* Right();
    private:
        FieldCoordinate dc,uc,lc,rc;

};

#endif // ROCKMOVEMENT_H
