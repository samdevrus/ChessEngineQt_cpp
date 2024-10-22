#include "field.h"

Field::Field(FieldCoordinate coordinate, Piece *piece):
    coordinate(coordinate)
{
    this->piece = piece;
}
