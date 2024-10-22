#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>
#include "../../kurs/chessEngine/chessbase.h"


class Tile: public QLabel
{
    Q_OBJECT
    public:
        //Fields
        int tileColor,piece,pieceColor,row,col,tileNum;
        char pieceName;
        //Constructors
        Tile(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {};
        Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){};

        //Methods
        void mousePressEvent(QMouseEvent *event);
        void display(char elem);
        void tileDisplay();
    signals:
        void move(FieldCoordinate fc1, FieldCoordinate fc2);
        void moved();
};

#endif // TILE_H
