#include "checkerboard.h"
#include <iostream>

checkerboard::checkerboard()
{
    int i=0;
    int j=0;
    Color color = white;
    while(i<10){
        j=i%2;              /* On veut placer les pieces diagonalement*/
        if(i==5){           /* On veut placer les pieces sur les 4 premières lignes de chaque côté*/
            i=i+2;
            color = black;
        }
        while(j<10){
            board[i][j]= new Piece(color);
            j=j+1;
        }
        i=i+1;
    }
}

void checkerboard::newKing(int x, int y)
{
    Color c = board[x][y]->getCouleur();
    board[x][y]=new king(c);
}

void checkerboard::destroy(int x, int y)
{
  // board[x][y]->~Piece();
   board[x][y]=nullptr;
}
void checkerboard::move(int x, int y, int dx, int dy)
{
   /* if(board[dx][dy]!=nullptr)
    {
        board[dx][dy]->~Piece();
    }*/
    board[dx][dy]=board[x][y];
    board[x][y]=nullptr;
}
