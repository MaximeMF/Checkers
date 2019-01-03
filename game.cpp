#include "game.h"


Game::Game() : player1(white), player2(black), checkerboard(), damier(){}

void Game::play()
{
    this->was_clicked=false;
    bool end = false;
    currentPlayer = &player1;
    QObject::connect(this, SIGNAL(clicked(int x, int y)), this, SLOT(clicked(int x, int y)));
    while(!end) {
        if(this->was_clicked){
            this->was_clicked=false;
            checkerboard.isPiece(clickPosX,clickPosY);
        }


        //..........

        changeTurn();
    }
}

void Game::changeTurn()
{
    if(currentPlayer == &player1)
        currentPlayer = &player2;
    else
        currentPlayer = &player1;
}

void Game::initialisation()
{

}

void Game::clicked(int x, int y){
    this->clickPosX=x;
    this->clickPosY=y;
    this->was_clicked=true;
}
