#include "checkerboard.h"
#include <iostream>

Checkerboard::Checkerboard()
{
    init();
}

void Checkerboard::init()
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            board[i][j] = nullptr;
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

bool Checkerboard::canPromote(int x, int y)
{
    bool ret;
    Color c = board[x][y]->getColor();
    if(c == white)
        y == 9 ? ret=true : ret=false;
    else //if(c == black) ?
        y == 0 ? ret=true : ret=false;
    return ret;
}

void Checkerboard::promotion(int x, int y)
{
    Color c = board[x][y]->getColor();
    delete board[x][y];
    board[x][y] = new King(c);
}

bool Checkerboard::canMove(int x, int y, int dx, int dy)
{
    bool ret = false;
    if(dynamic_cast<King*>(board[x][y])) { // si la piece est une dame
        if(abs(dx-x)==abs(dy-y)) // si le déplacement est bien en diagonale
            if(board[dx][dy] != nullptr) // si la case ciblée est bien vide
                for(int i=1; i<abs(dx-x); i++) { // si chaque case sur le trajet est bien vide
                    int deltaX = dx-x, deltaY = dy-y; //permet de vérifier le trajet selon la direction
                    if(deltaX<0 && deltaY<0) { //en bas à gauche
                        if(board[x-i][y-i] != nullptr)
                            ret = true;
                    }
                    else if(deltaX>0 && deltaY<0) { //en bas à droite
                        if(board[x-i][y+i] != nullptr)
                            ret = true;
                    }
                    else if(deltaX<0 && deltaY>0) { //en haut à gauche
                        if(board[x+i][y-i] != nullptr)
                            ret = true;
                    }
                    else { //en haut à droite
                        if(board[x+i][y+i] != nullptr)
                            ret = true;
                    }
                }
    }
    else { // si la piece n'est pas une dame
        if(dy-y==1 && abs(dx-x)==1) // si le déplacement est bien d'une case en diagonale en direction de l'autre bout du plateau
            if(board[dx][dy] != nullptr) // si la case ciblée est bien vide
                ret = true;
    }
    return ret;
}

void Checkerboard::move(int x, int y, int dx, int dy)
{
    board[dx][dy] = board[x][y];
    delete board[x][y];
    board[x][y] = nullptr;
}

void Checkerboard::remove(int x, int y)
{
    delete board[x][y];
    board[x][y] = nullptr;
}

bool Checkerboard::isPiece(int x, int y)
{
    return (board[x][y] != nullptr);
}
Color Checkerboard::getColorPiece(int x, int y)
{
    return(board[x][y]->getColor());
}
