#include "checkerboard.h"
#include <iostream>

using namespace std;

Checkerboard::Checkerboard()
{
    init();
}

void Checkerboard::init() {
    Color color = white;
    for(int j=0; j<10; j++) {
        if(j==4) {
            j=j+2;
            color = black;
        }
        for(int i=0; i<10; i++) {
            if(j%2==0) {
                if(i%2==0)
                    board[i][j] = new Piece(color);
            }
            else {
                if(i%2==1)
                    board[i][j] = new Piece(color);
            }
        }
    }
}

void Checkerboard::newKing(int x, int y)
{
    Color c = board[x][y]->getColor();
    board[x][y]=new King(c);
}

void Checkerboard::destroy(int x, int y)
{
  // board[x][y]->~Piece();
   board[x][y]=nullptr;
}

void Checkerboard::move(int x, int y, int dx, int dy)
{
   /* if(board[dx][dy]!=nullptr)
    {
        board[dx][dy]->~Piece();
    }*/
    board[dx][dy]=board[x][y];
    board[x][y]=nullptr;
}
