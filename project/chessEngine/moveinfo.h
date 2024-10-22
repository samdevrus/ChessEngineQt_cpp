#ifndef MOVEINFO_H
#define MOVEINFO_H
#include "piece.h"

struct MoveInfo {
    MoveInfo() {

    }

    MoveInfo(Field* fSource, Field* fDestination) {
        source = fSource;
        destination = fDestination;
        pSource = source->getPiece();
        pDestination = destination->getPiece();
        pieceAttacked =!destination->isEmpty();
     //   qDebug()<<source<<destination<<pSource<<pDestination;
    }
    QString toText() {
        if (!pieceAttacked) {
            return pSource->toText()+source->getCoordinate().toText()+
                "-"+destination->getCoordinate().toText();
        } else {
            //qDebug()<<"a";
            return source->getPiece()->toText()+":"+destination->getCoordinate().toText();
        }
    }

    bool pieceAttacked;
    Field *source,
           *destination;
    Piece *pSource,
           *pDestination;
};

#endif // MOVEINFO_H
