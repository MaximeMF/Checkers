#include "game.h"
#include "wrongCase.h"


Game::Game(Damier *damier) : QObject(), player1(white), player2(black), checkerboard(){this->damier=damier;}

void Game::play()
{
    currentPlayer = &player1;
    connect(this->damier, SIGNAL(clicked(int, int)), this, SLOT(clicked(int, int)));
    int i=0;
    int j=0;
    while(i<10){
        j=0;
        while(j<10){
            if(checkerboard.isPiece(j,i)){
                if((checkerboard.getColorPiece(j,i)) == white){
                    damier->setSquare(j, i, "Pblanc_Cnoire.png");
                    printf("piece at %d, %d \n",i,j);
                }
                else{
                    damier->setSquare(j, i, "Pnoir_Cnoire.png");
                }
            }
            else{
                if((i+j)%2==1){
                    damier->setSquare(j,i, "caseBlanche.png");
                 }
                 else{
                     damier->setSquare(j,i, "caseNoire.png");
                 }
            }
            j=j+1;
        }
        i=i+1;
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

void Game::clicked(int y, int x){
    qDebug("t'as bien cliqué connard");
    if(checkerboard.isPiece(x,y)){
        if(checkerboard.getColorPiece(x,y)== currentPlayer->getColor()){
            qDebug("on passe au deuxième clique !");
            this->clickPosX=x;
            this->clickPosY=y;
            disconnect(damier, SIGNAL(clicked(int, int)), this, SLOT(clicked(int, int)));
            connect(this->damier, SIGNAL(clicked(int, int)), this, SLOT(clicked2(int, int)));
        }


    }


  //  this->was_clicked=true;

}

void Game::clicked2(int dy, int dx){
    printf("t'as bien cliqué 2 fois connard");
    if(this->clickPosX==dx and this->clickPosY==dy){
        disconnect(damier, SIGNAL(clicked(int, int)), this, SLOT(clicked2(int, int)));
        connect(damier, SIGNAL(clicked(int, int)), this, SLOT(clicked(int, int)));
    }
    else if(checkerboard.canMove(this->clickPosX, this->clickPosY, dx, dy)){
        printf("Et c'est un move reussi");
        checkerboard.move(this->clickPosX, this->clickPosY, dx, dy);
        damier->setSquare(clickPosX, clickPosY, "caseNoire");
        if((currentPlayer->getColor()) == white){
            damier->setSquare(dx, dy, "Pblanc_Cnoire");
        }
        else{
            damier->setSquare(dx, dy, "Pnoir_Cnoire");
        }

        if(checkerboard.canPromote(dx,dy)){
            checkerboard.promotion(dx,dy);
            if((currentPlayer->getColor()) == white){
                damier->setSquare(dx, dy, "Pblanc_CnoireReine");
            }
            else{
                damier->setSquare(dx, dy, "Pnoir_CnoireReine");
            }
        }
        disconnect(damier, SIGNAL(clicked(int, int)), this, SLOT(clicked2(int, int)));
        connect(damier, SIGNAL(clicked(int, int)), this, SLOT(clicked(int, int)));
        changeTurn();
    }
    else{
        QMessageBox::information(nullptr,"Wrong click","You cannot move to this case");
        //throw WrongCase();
    }
}
