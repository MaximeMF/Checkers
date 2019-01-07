#include "checkerboard.h"
#include <iostream>
#include <QDebug>

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
    else
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
    if(isKing(x,y)) { // si la piece est une dame
        if(abs(dx-x)==abs(dy-y)) { // si le déplacement est bien en diagonale
            if(board[dx][dy] == nullptr) { // si la case ciblée est bien vide
                int deltaX = dx-x, deltaY = dy-y; //permet de vérifier le trajet selon la direction
                for(int i=1; i<abs(deltaX); i++) { // si chaque case sur le trajet est bien vide
                    if(deltaX<0 && deltaY<0) { //en bas à gauche
                        if(board[x-i][y-i] != nullptr)
                            return false;
                    }
                    else if(deltaX>0 && deltaY<0) { //en bas à droite
                        if(board[x-i][y+i] != nullptr)
                            return false;
                    }
                    else if(deltaX<0 && deltaY>0) { //en haut à gauche
                        if(board[x+i][y-i] != nullptr)
                            return false;
                    }
                    else { //en haut à droite
                        if(board[x+i][y+i] != nullptr)
                            return false;
                    }
                }
                return true;
            }
        }
    }
    else { // si la piece n'est pas une dame
        if(abs(dx-x)==1) { // si le déplacement est d'une case sur la droite ou la gauche
            if((board[x][y]->getColor()==white && dy-y==1) || (board[x][y]->getColor()==black && dy-y==-1)) { // si le déplacement est bien d'une case vers le haut ou le bas selon la couleur de la pièce
                if(board[dx][dy] == nullptr) // si la case ciblée est bien vide
                    return true;
            }
        }
    }
    return false;
}

void Checkerboard::move(int x, int y, int dx, int dy)
{
    board[dx][dy] = board[x][y];
    board[x][y] = nullptr;
}

bool Checkerboard::canRemove(int x, int y, int dx, int dy, int* rx, int* ry)
{
    if(isKing(x,y)) { // si la piece est une dame
        // TODO
    }
    else { // si la piece n'est pas une dame
        if(abs(dx-x)==2 && abs(dy-y)==2) { // si le déplacement est de 2 cases en diagonale
            if(board[dx][dy] == nullptr) { // si la case ciblée est bien vide
                int deltaX = dx-x, deltaY = dy-y; //permet de vérifier le trajet selon la direction
                if(deltaX<0 && deltaY<0) { // en bas à gauche
                    if(board[x-1][y-1]!=nullptr && board[x-1][y-1]->getColor()!=board[x][y]->getColor()) { // si la case est occupée par un ennemi
                        *rx = x-1;
                        *ry = y-1;
                        return true;
                    }
                }
                else if(deltaX>0 && deltaY<0) { //en bas à droite
                    if(board[x+1][y-1]!=nullptr && board[x+1][y-1]->getColor()!=board[x][y]->getColor()) { // si la case est occupée par un ennemi
                        *rx = x+1;
                        *ry = y-1;
                        return true;
                    }
                }
                else if(deltaX<0 && deltaY>0) { //en haut à gauche
                    if(board[x-1][y+1]!=nullptr && board[x-1][y+1]->getColor()!=board[x][y]->getColor()) { // si la case est occupée par un ennemi
                        *rx = x-1;
                        *ry = y+1;
                        return true;
                    }
                }
                else { //en haut à droite
                    if(board[x+1][y+1]!=nullptr && board[x+1][y+1]->getColor()!=board[x][y]->getColor()) { // si la case est occupée par un ennemi
                        *rx = x+1;
                        *ry = y+1;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Checkerboard::remove(int x, int y, int dx, int dy, int rx, int ry)
{
    move(x, y, dx, dy);
    delete board[rx][ry];
    board[rx][ry] = nullptr;
}

bool Checkerboard::isPiece(int x, int y)
{
    return (board[x][y] != nullptr);
}

Color Checkerboard::getColorPiece(int x, int y)
{
    return (board[x][y]->getColor());
}

bool Checkerboard::isKing(int x, int y)
{
    return (dynamic_cast<King*>(board[x][y]) != nullptr);
}
