#include <QCoreApplication>
#include "board.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"boardTest";
    Board chessBoard;
    chessBoard.print();
    chessBoard.makeMove(FieldCoordinate(5,2),FieldCoordinate(5,4));
    chessBoard.print();
    chessBoard.makeMove(FieldCoordinate(4,7),FieldCoordinate(4,5));
    chessBoard.print();
    chessBoard.makeMove(FieldCoordinate(1,1),FieldCoordinate(5,1));
    chessBoard.print();
    chessBoard.makeMove(FieldCoordinate(5,1),FieldCoordinate(5,3));

    chessBoard.makeMove(FieldCoordinate(5,3),FieldCoordinate(4,3));
    chessBoard.print();
//    chessBoard.makeMove(FieldCoordinate(5,4),FieldCoordinate(4,5));

//    chessBoard.print();
    chessBoard.unmakeMove();
    chessBoard.print();
    Piece* p =  chessBoard.getField(FieldCoordinate(4,3))->getPiece();
    QList<MoveInfo> mif = chessBoard.getPieceMoves(p);

    qDebug()<<"possibleMoves:"<<mif.count();
    foreach (MoveInfo mi, mif) {
        qDebug()<<mi.toText();
    }

    qDebug()<<"end";
    return a.exec();
}
