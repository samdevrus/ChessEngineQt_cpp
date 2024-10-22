#ifndef SQUARE_H
#define SQUARE_H
#include "QChar"
#include "QString"

const int BOARD_SIZE = 8;

const int SQ_UP = 8;
const int SQ_DOWN = -8;


class Square
{
    public:
        Square(QChar vertPos,int horizPos);
        Square(int squarePosition);
        Square* copySquare(int squarePosDiff);
        void invert() {
            textPosition = "";
            position = BOARD_SIZE*BOARD_SIZE - position;

        }

        bool isValid() {
            return position>=0&&position<64;
        }

    private:
        QString textPosition;
        int position;
};

#endif // SQUARE_H
