#ifndef MOVEMAKE_H
#define MOVEMAKE_H
#include <QObject>
#include "../../kurs/chessEngine/board.h"
#include "../../kurs/chessEngine/positionanalyserv1.h"
#include "tile.h"

extern int turn;
extern Tile *tile[8][8];

class MoveMake :public QObject{
    Q_OBJECT
    public:
    MoveMake():QObject() {

    }
    PositionAnalyserV1 an;
    Board board;
    void move(MoveInfo mi);
    public slots:
        void makeMove(FieldCoordinate fc1, FieldCoordinate fc2) {
            //qDebug()<<"makeMove";
            //qDebug()<<(int)fc1.x<<(int)fc1.y;
            //qDebug()<<(int)fc2.x<<(int)fc2.y;

            board.makeMove(fc1,fc2);
          //  board.print();
            an.analyse();
            an.makeMove();
            //qDebug()<<turn;
            turn=(turn+1)%2;
            //qDebug()<<turn;
            MoveInfo lm = board.getLastMove();
            move(lm);
           // turn=0;
        }
};

#endif // MOVEMAKE_H
