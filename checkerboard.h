#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H
#include "piece.h"

class checkerboard
{
    Piece *board[10][10];
public:
    checkerboard();

    void newKing(int x, int y);
    void destroy(int x, int y);                 //void destroy(piece piece)
    void move(int x, int y, int dx, int dy);
};


#endif // CHECKERBOARD_H
