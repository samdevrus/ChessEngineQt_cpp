#include "rockmovement.h"

RockMovement::RockMovement(FieldCoordinate coordinate):
    PieceMovement(coordinate),
  uc(coordinate),
  lc(coordinate),
  rc(coordinate),
  dc(coordinate)
{
}

PieceMove* RockMovement::Up() {
    uc = uc.up();
    if (!uc.isValid()) {
        return NULL;
    }
    return new PieceMove(uc);
}
PieceMove* RockMovement::Down() {
    dc = dc.down();
    if (!dc.isValid()) {
        return NULL;
    }
    return new PieceMove(dc);
}

PieceMove* RockMovement::Left() {
    lc = lc.left();
    if (!lc.isValid()) {
        return NULL;
    }
    return new PieceMove(lc);
}

PieceMove* RockMovement::Right() {
    rc = rc.right();
    if (!rc.isValid()) {
        return NULL;
    }
    return new PieceMove(rc);
}
