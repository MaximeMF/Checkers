#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H
#include "piece.h"
#include "color.h"
#include "king.h"

class Checkerboard
{
public:
    Checkerboard();
    void newKing(int x, int y);
    void destroy(int x, int y);                 //void destroy(piece piece)
    void move(int x, int y, int dx, int dy);
private:
    Piece* board[10][10];
    void init();
};

#endif // CHECKERBOARD_H
