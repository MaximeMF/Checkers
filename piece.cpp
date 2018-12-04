#include "piece.h"

Piece::Piece(Color c) : COLOR(c){}

Piece::~Piece() {}

Color Piece::getColor()
{
    return COLOR;
}
