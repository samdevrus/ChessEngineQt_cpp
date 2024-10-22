#include "rock.h"
#include "rockmovement.h"

Rock::Rock(PieceColor pieceColor, Field &field, IFieldManager *fieldManager):
    Piece(pieceColor, field)
{
    this->type = ROCK;
    this->fieldManager = fieldManager;
}


QList<PieceMove *> Rock::pieceMoves() {
    QList<PieceMove*> moves;
    RockMovement rockMovement(currentField->getCoordinate());
    PieceMove* pm = rockMovement.Up();
  //  qDebug()<<pm;
    while(pm!=NULL) {
        Field* f = fieldManager->getField(pm->getDestination());

        if (!f->isEmpty()) {
            if (f->getPiece()->getColor()!=color) {
                moves.append(pm);
            }
            pm = NULL;
        } else {
            moves.append(pm);
            pm = rockMovement.Up();
        }
    }
    pm = rockMovement.Down();
//    qDebug()<<pm;
    while(pm!=NULL) {
        Field* f = fieldManager->getField(pm->getDestination());

        if (!f->isEmpty()) {
            if (f->getPiece()->getColor()!=color) {
                moves.append(pm);
            }
            pm = NULL;
        } else {
            moves.append(pm);
            pm = rockMovement.Down();
        }
    }
    pm = rockMovement.Left();
    while(pm!=NULL) {
        Field* f = fieldManager->getField(pm->getDestination());

        if (!f->isEmpty()) {
            if (f->getPiece()->getColor()!=color) {
                moves.append(pm);
            }
            pm = NULL;
        } else {
            moves.append(pm);
            pm = rockMovement.Left();
        }
    }
    pm = rockMovement.Right();
    while(pm!=NULL) {
        Field* f = fieldManager->getField(pm->getDestination());

        if (!f->isEmpty()) {
            if (f->getPiece()->getColor()!=color) {
                moves.append(pm);
            }
            pm = NULL;
        } else {
            moves.append(pm);
            pm = rockMovement.Right();
        }
    }

  //  qDebug()<<moves.count();
    return moves;
}
