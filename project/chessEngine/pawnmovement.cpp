#include "pawnmovement.h"
#include "QDebug"

PawnMovement::PawnMovement(FieldCoordinate coordinate, PieceColor color):
    PieceMovement(coordinate),
    color(color)
{
}

QList<PieceMove*> PawnMovement::moveOneField() {
    QList<PieceMove*> moves;
    FieldCoordinate fc(0,0);
    switch(color) {
        case WHITE:{ fc = coordinate.up();break;}
        case BLACK:{ fc = coordinate.down();break;}
    }
    if (fc.isValid()) {
        PieceMove* pm = new PieceMove(fc);
        pm->flags.mustBeEmpty = true;
        moves.append(pm);
    }

    return moves;
}

QList<PieceMove*> PawnMovement::moveTwoField() {
    QList<PieceMove*> moves;
    FieldCoordinate fc;
    switch(color) {
        case WHITE: fc = coordinate.up(2);break;
        case BLACK: fc = coordinate.down(2);break;
    }
    if (fc.isValid()) {
        PieceMove* pm = new PieceMove(fc);
        pm->flags.mustBeEmpty = true;
        moves.append(pm);
    }
    return moves;
}

QList<PieceMove*> PawnMovement::attack() {
    QList<PieceMove*> moves;
    FieldCoordinate fcLeft,
                     fcRight;
    switch(color) {
        case WHITE: {
            fcLeft  = coordinate.upLeft();
            fcRight = coordinate.upRight();
            break;
            }
        case BLACK: {
            fcLeft  = coordinate.downLeft();
            fcRight = coordinate.downRight();
            break;
        }
    }
    if (fcLeft.isValid()) {
        PieceMove* pm = new PieceMove(fcLeft);
        pm->flags.mustAttack = true;
        pm->flags.takeIfPawnMoved = true;
        moves.append(pm);
    }
    if (fcRight.isValid()) {
        PieceMove* pm = new PieceMove(fcRight);
        pm->flags.mustAttack = true;
        pm->flags.takeIfPawnMoved = true;
        moves.append(pm);
    }

    return moves;
}
