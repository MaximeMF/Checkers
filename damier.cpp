#include <QtWidgets>
#include <iostream>
#include <iostream>
#include "damier.h"
#include "square.h"

Damier::Damier() : QMainWindow()
{
    this->setFixedSize(800,800);
    layout = new QGridLayout;
    this->setLayout(layout);
    this->createBoard();

}

void Damier::createBoard()
{

    int i=0;
    int j=0;
    while(i<10){
        layout->setRowStretch(i,80);
        j=0;
        while(j<10){
            layout->setColumnStretch(j,80);
            Square *square = new Square(this,i,j);
            QPixmap *pixmap_img;
            if((i+j)%2==1){
                pixmap_img = new QPixmap("WhiteS.png");
            }
            else{
                pixmap_img = new QPixmap("BlackS.png");
            }
            square->setPixmap(*pixmap_img);
            square->setFixedSize(80,80);
            std::cout << i <<"ddd"<< j << std::endl;
            this->layout->addWidget(square,i,j);
             std::cout << "posX : " <<square->posX<< "and posY : "<< square->posY << std::endl;
            //square->show();
            j=j+1;
        }
        i=i+1;
    }

}
