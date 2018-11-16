#ifndef PIECE_H
#define PIECE_H
#include "color.h"


class Piece
{
    Color color;
public:
    Piece(Color);
    ~Piece();
    Color getCouleur();
};

#endif // PIECE_H
