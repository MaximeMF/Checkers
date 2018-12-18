#include <QtWidgets>
#include <iostream>
#include <iostream>
#include "damier.h"

<<<<<<< HEAD

Damier::Damier() :
QDialog()
{
    //this->setFixedSize(800,800);
    resize(800,800);
   // mainlayout = new Qmainlayout(this);
    mainlayout = new QGridLayout(this);
    mainlayout->setObjectName(QStringLiteral("layout"));
    mainlayout->setContentsMargins(10,10,10,10);
    mainlayout->setColumnMinimumWidth(1,80);
    mainlayout->setColumnMinimumWidth(5,80);
    mainlayout->setSpacing(0);
    mainlayout->setRowMinimumHeight(1,80);
    mainlayout->setRowStretch(1,1);
    mainlayout->setColumnStretch(1,1);
    //layout->setMinimumSize(500,500);
    //layout->setMaximumSize(800,800);
    //setLayout(layout);
    createBoard();
=======
Damier::Damier() : QMainWindow()
{
    //this->setFixedSize(800,800);
    this->resize(800,800);
    layout = new QHBoxLayout(this);
    layout->setObjectName(QStringLiteral("layout"));
    layout->setContentsMargins(8,8,8,8);
    this->setLayout(layout);
    this->createBoard();
>>>>>>> e843a57bdef8ad7e164af1829a698dcca97b0677
}

void Damier::createBoard()
{
<<<<<<< HEAD
    Square *square;
  
 int i=0;
 int j=0;
   while(i<10){
        j=0;
       while(j<10)
       {
            square = new Square(this,0,0);
            square->setMinimumSize(80,80);
            square->setMaximumSize(80,80);
            QIcon *icon;
            if((i+j)%2==1) {
               icon = new QIcon("BlackS.png");
=======
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
>>>>>>> e843a57bdef8ad7e164af1829a698dcca97b0677
            }
            else{
                icon = new QIcon("WhiteS.png");
            }
<<<<<<< HEAD
            square->setIcon(*icon);
            square->setIconSize(QSize(80,80));
            square->show();
            mainlayout->addWidget(square,i,j, Qt::AlignCenter);
            mysquares.push_back(square);
=======
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
>>>>>>> e843a57bdef8ad7e164af1829a698dcca97b0677
            j=j+1;
        }
        i=i+1;
    }
}
