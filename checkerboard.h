#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H
#include "piece.h"
#include "color.h"
#include "king.h"

class Checkerboard
{
public:
    Checkerboard();
    bool isPiece(int x, int y);
    bool canPromote(int x, int y);
    void promotion(int x, int y);
    bool canMove(int x, int y, int dx, int dy);
    void move(int x, int y, int dx, int dy);
    void remove(int x, int y);
private:
    Piece* board[10][10];
    void init();
};

#endif // CHECKERBOARD_H
