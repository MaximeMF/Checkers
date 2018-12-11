#include <QtWidgets>
#include <iostream>
#include <iostream>
#include "damier.h"
#include "square.h"

Damier::Damier() : QMainWindow()
{
    //this->setFixedSize(800,800);
    this->resize(800,800);
    layout = new QHBoxLayout(this);
    layout->setObjectName(QStringLiteral("layout"));
    layout->setContentsMargins(8,8,8,8);
    this->setLayout(layout);
    this->createBoard();
}

void Damier::createBoard()
{
    int i=0;
    int j=0;
    while(i<10){
        //layout->setRowStretch(i,1);
        //layout->setRowMinimumHeight(i, 80);
        j=0;
        while(j<10){
            //layout->setColumnStretch(j,1);
            //layout->setColumnMinimumWidth(j, 80);
            Square *square = new Square(this,i,j);
            square->setMinimumSize(80,80);
            square->setMaximumSize(80,80);
            QPixmap *pixmap_img;
            if((i+j)%2==1) {
                pixmap_img = new QPixmap("WhiteS.png");
            }
            else{
                pixmap_img = new QPixmap("BlackS.png");
            }
            //square->setPixmap(*pixmap_img);
            QIcon *icon;
            icon = new QIcon("WhiteS.png");
            square->setIcon(*icon);
            square->setIconSize(QSize(80,80));
            //square->setFixedSize(80,80);
            std::cout << i <<"ddd"<< j << std::endl;
            layout->addWidget(square);
             std::cout << "posX : " <<square->posX<< "and posY : "<< square->posY << std::endl;
            //square->show();
            j=j+1;
        }
        i=i+1;
    }
}
