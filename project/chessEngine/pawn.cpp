#include "pawn.h"
#include "pawnmovement.h"
#include "QDebug"

Pawn::Pawn(PieceColor pieceColor, Field &field):
    Piece(pieceColor,field)
{
    type = PAWN;
}


QList<PieceMove *> Pawn::pieceMoves() {
    QList<PieceMove*> moves;
    PawnMovement pawnMovement(currentField->getCoordinate(),color);

    moves.append(pawnMovement.moveOneField());
    if (!moved)   {
        moves.append(pawnMovement.moveTwoField());
    }

    moves.append(pawnMovement.attack());
    return moves;
}
