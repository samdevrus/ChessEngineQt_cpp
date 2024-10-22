#ifndef PIECEMOVE_H
#define PIECEMOVE_H
#include "field.h"
#include "QString"
//Ограничения для движения фигуры
struct MoveFlags {
    MoveFlags():
        mustAttack(false),
        mustBeEmpty(false),
        firstMove(false),
        takeIfPawnMoved(false)
    {

    }

    bool mustAttack,
         takeIfPawnMoved,
         mustBeEmpty,
         firstMove;
};

//Информация о возможном ходе
class PieceMove
{
    public:
        PieceMove(FieldCoordinate destination);
        MoveFlags flags;
        FieldCoordinate getDestination() {
            return destination;
        }

    protected:
        FieldCoordinate destination;
};

#endif // PIECEMOVE_H
