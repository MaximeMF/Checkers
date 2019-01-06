#include "game.h"


Game::Game() : player1(white), player2(black), checkerboard(){damier = new Damier();}

void Game::play()
{
    this->was_clicked=false;
    bool end = false;
    currentPlayer = &player1;
    QObject::connect(this->damier, SIGNAL(clicked(int x, int y)), this, SLOT(clicked(int x, int y)));
    while(!end) {
        /*if(this->was_clicked){
            this->was_clicked=false;
            checkerboard.isPiece(clickPosX,clickPosY);
        }*/


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
    if(checkerboard.isPiece(clickPosX,clickPosY)){
        if(checkerboard.getColorPiece(x,y)==const currentPlayer->getColor()){
            this->clickPosX=x;
            this->clickPosY=y;
            QObject->disconnect(this, SIGNAL(clicked(int x, int y)), this, SLOT(clicked(int x, int y)));
            connect(this->damier, SIGNAL(clicked(int x, int y)), this, SLOT(clicked2(int x, int y)));
        }

    }


  //  this->was_clicked=true;

}

void Game::clicked2(int dx, int dy){
    if(this->clickPosX==dx and this->clickPosY==dy){
        disconnect(damier, SIGNAL(clicked(int x, int y)), this, SLOT(clicked2(int x, int y)));
        connect(damier, SIGNAL(clicked(int x, int y)), this, SLOT(clicked(int x, int y)));
    }
    else if(checkerboard.canMove(this->clickPosX, this->clickPosY, dx, dy)){
        checkerboard.move(this->clickPosX, this->clickPosY, dx, dy);
        if(checkerboard.canPromote(dx,dy)){
            checkerboard.promotion(dx,dy);
        }
        disconnect(damier, SIGNAL(clicked(int x, int y)), this, SLOT(clicked2(int x, int y)));
        connect(damier, SIGNAL(clicked(int x, int y)), this, SLOT(clicked(int x, int y)));
        changeTurn();
    }
    else{
        //damier.message d'erreur
    }
}
