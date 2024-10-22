#include "bishopmovement.h"

BishopMovement::BishopMovement(FieldCoordinate coordinate):
    PieceMovement(coordinate),
  urc(coordinate),
  ulc(coordinate),
  drc(coordinate),
  dlc(coordinate)
{
}

PieceMove* BishopMovement::UpLeft() {
    ulc = ulc.upLeft();
    if (!ulc.isValid()) {
        return NULL;
    }
    return new PieceMove(ulc);
}
PieceMove* BishopMovement::UpRight() {
    urc = urc.upRight();
    if (!urc.isValid()) {
        return NULL;
    }
    return new PieceMove(urc);
}

PieceMove* BishopMovement::DownLeft() {
    dlc = dlc.downLeft();
    if (!dlc.isValid()) {
        return NULL;
    }
    return new PieceMove(dlc);
}

PieceMove* BishopMovement::DownRight() {
    drc = drc.downRight();
    if (!drc.isValid()) {
        return NULL;
    }
    return new PieceMove(drc);
}
