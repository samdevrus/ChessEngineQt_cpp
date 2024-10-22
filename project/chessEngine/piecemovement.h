#ifndef PIECEMOVEMENT_H
#define PIECEMOVEMENT_H
#include "field.h"
#include "piecemove.h"
class PieceMovement
{
    public:
        PieceMovement(FieldCoordinate coordinate);
    protected:
        FieldCoordinate coordinate;
};

#endif // PIECEMOVEMENT_H
