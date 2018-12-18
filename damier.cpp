#include <QtWidgets>
#include <iostream>
#include <iostream>
#include "damier.h"


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
}

void Damier::createBoard()
{
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
               icon = new QIcon("WhiteS.png");
            }
            else{
                icon = new QIcon("BlackS.png");
            }
            square->setIcon(*icon);
            square->setIconSize(QSize(80,80));
            square->show();
            mainlayout->addWidget(square,i,j, Qt::AlignCenter);
            mysquares.push_back(square);
            j=j+1;
        }
        i=i+1;
    }
}
