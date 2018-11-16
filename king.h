#ifndef KING_H
#define KING_H
#include "piece.h"

class king : public Piece
{
public:
    king(Color color) : Piece(color){}
};
#endif // KING_H
