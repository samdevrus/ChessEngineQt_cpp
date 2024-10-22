#include "movemake.h"
void MoveMake::move(MoveInfo mi) {

    tile[8-mi.source->getCoordinate().y][mi.source->getCoordinate().x-1]->piece =0;
    tile[8-mi.source->getCoordinate().y][mi.source->getCoordinate().x-1]->display(' ');
    tile[8-mi.destination->getCoordinate().y][mi.destination->getCoordinate().x-1]->piece =1;
    tile[8-mi.destination->getCoordinate().y][mi.destination->getCoordinate().x-1]->pieceColor =(mi.pSource->getColor()+1)%2;
    char figure = mi.pSource->toText().at(0).toLatin1();
    tile[8-mi.destination->getCoordinate().y][mi.destination->getCoordinate().x-1]->display(figure);
}
