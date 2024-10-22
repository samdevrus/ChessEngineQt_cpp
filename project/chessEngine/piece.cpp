#include "piece.h"

Piece::Piece(PieceColor pieceColor, Field &field):
    color(pieceColor),
    currentField(&field),
    moved(0),
    fieldManager(0)
{
}
