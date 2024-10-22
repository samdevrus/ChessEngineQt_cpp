#ifndef BOARD_H
#define BOARD_H
#include "QList"

#include "piece.h"
#include "moveinfo.h"
#include "ifieldmanager.h"

class Board : public IFieldManager
{
    public:
        Board();
        void makeMove(FieldCoordinate source, FieldCoordinate cDestination);
        void unmakeMove();
        QList<Piece*> getPieces(PieceColor color);
        QList<MoveInfo> getPieceMoves(Piece* piece);
        void print();
        Field* getField(FieldCoordinate c);
    protected:
        void setup();
        bool validatePieceMove(Piece *piece, PieceMove& pm);
        QList<Piece*> pieces;
        QList<Field*> fields;
        QList<MoveInfo> moves;
        PieceColor currentSideMove;
};

#endif // BOARD_H
