#include "square.h"

Square::Square(QChar vertPos, int horizPos)
{
    //TODO: validate
    textPosition = vertPos + QString::number(horizPos);
    position = QString(vertPos).toInt()*BOARD_SIZE+horizPos;
}

Square::Square(int squarePosition) {
    position = squarePosition;
}

Square* Square::copySquare(int squarePosDiff) {

    return new Square(position+squarePosDiff);
}
