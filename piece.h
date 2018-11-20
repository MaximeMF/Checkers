#ifndef PIECE_H
#define PIECE_H
#include "color.h"

class Piece
{
public:
    Piece(Color);
    ~Piece();
    Color getColor();

protected:
    const Color COLOR;
};

#endif // PIECE_H
