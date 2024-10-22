#include "QDebug"

#include "board.h"
#include "pawn.h"
#include "rock.h"

Board::Board():
    currentSideMove(WHITE)
{
    setup();
}

void Board::setup() {
    for (char y=1;y<=SQUARE_SIDE;y++) {
        for (char x=1;x<=SQUARE_SIDE;x++) {
            Field *f = new Field(FieldCoordinate(x,y));
            if (y==2) {
                Pawn* p = new Pawn(WHITE,*f);
                f->setPiece(*p);
                pieces.append(p);
            }
            if (y==7) {
                Pawn* p = new Pawn(BLACK,*f);
                f->setPiece(*p);
                pieces.append(p);
            }
            if (y==1 && (x==1 || x==8)) {
                Rock* p = new Rock(WHITE,*f,this);
                f->setPiece(*p);
                pieces.append(p);
            }
            if (y==8 && (x==1 || x==8)) {
                Rock* p = new Rock(BLACK,*f,this);
                f->setPiece(*p);
                pieces.append(p);
            }
            fields.append(f);
        }
    }
}

QList<Piece*> Board::getPieces(PieceColor color) {
    QList<Piece*> neededPieces;

    for (char i=0;i<pieces.count();i++) {
        if (pieces.at(i)->getColor() == color) {
            neededPieces.append(pieces.at(i));
        }
    }
    return neededPieces;
}

Field* Board::getField(FieldCoordinate c) {
    for (char i = 0; i< fields.count(); i++) {
        if (fields.at(i)->getCoordinate()==c) {
            return fields.at(i);
        }
    }
    qDebug()<<"not found";
    return NULL;
}

void Board::makeMove(FieldCoordinate cSource, FieldCoordinate cDestination) {
    Field *source = getField(cSource),
          *destination = getField(cDestination);
    moves.append(MoveInfo(source,destination));
    //destination->setPiece(*source->getPiece());
    //source->removePiece();
    //destination->getPiece()->setField(destination);
    source->getPiece()->move();
    destination->setPiece(*(source->removePiece())).setField(destination);

}

QList<MoveInfo> Board::getPieceMoves(Piece *piece){
    QList<PieceMove*> pieceMoves = piece->getPieceMoves();
    QList<MoveInfo> validMoves;
    foreach (PieceMove* pm, pieceMoves) {
        if (validatePieceMove(piece,*pm)) {
            Field* source = &piece->getField(),
                    *destination = getField(pm->getDestination());
            MoveInfo mi(source,destination);
            validMoves.append(mi);
        }
    }
    return validMoves;
}

void Board::unmakeMove() {
    MoveInfo mi = moves.last();
    mi.source->setPiece(*mi.pSource);
    mi.destination->setPiece(*mi.pDestination);
    if (!mi.source->isEmpty()) {
        mi.source->getPiece()->setField(mi.source);
    }
    if (!mi.destination->isEmpty()) {
        mi.destination->getPiece()->setField(mi.destination);
    }
    mi.pSource->unmove();
    moves.removeLast();
}

bool Board::validatePieceMove(Piece* piece,PieceMove &pm) {
    Field* f = getField(pm.getDestination());
    if (pm.flags.mustBeEmpty && !f->isEmpty()) {
        return false;
    }


    // валидация для взятия на проходе
    if (pm.flags.mustAttack && pm.flags.takeIfPawnMoved && f->isEmpty() &&
            moves.count()>0) {

        MoveInfo mi = moves.last();
       // qDebug()<<"val pawn"<<mi.toText();

        int xd =abs(mi.source->getCoordinate().y - mi.destination->getCoordinate().y);
       // qDebug()<<xd;

        if (xd==2 && (pm.getDestination().x==mi.pSource->getField().getCoordinate().x)
                && (piece->getField().getCoordinate().y == mi.pSource->getField().getCoordinate().y)
                && mi.pSource->getType()==PAWN)
        return true;
    }

    if (pm.flags.mustAttack &&
            (f->isEmpty() || (!f->isEmpty() &&
                              f->getPiece()->getColor()==piece->getColor()) )) {
        return false;
    }
    if (pm.flags.firstMove && piece->isMoved()) {
        return false;
    }
    return true;
}

void Board::print() {
    qDebug()<<"CHESSBOARD:";
    for (char y=SQUARE_SIDE;y>0;y--) {
        QString line = "|";
        for (char x=1;x<=SQUARE_SIDE;x++) {
//            qDebug()<<(int)x<<(int)y;
            Field* f = getField(FieldCoordinate(x,y));
            //qDebug()<<f;
            if (f->isEmpty()) {
                line.append(" ");
            } else {
                line.append(f->getPiece()->toText());
            }
            line.append("|");
        }
        qDebug()<<line;
    }
//    Field* f = getField(FieldCoordinate(5,2));
//    Piece* p = f->getPiece();
//    QList<PieceMove*> moves = p->getPieceMoves();
//    qDebug()<<moves.count();
//    foreach (PieceMove* move, moves) {
//        qDebug()<<move->getDestination();
//    }

}
