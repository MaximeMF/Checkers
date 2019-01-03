#include <QtWidgets>
#include <iostream>
#include "damier.h"


Damier::Damier() :
QDialog()
{
    //this->setFixedSize(850,850);
    resize(850,850);
   // mainlayout = new Qmainlayout(this);
    mainlayout = new QGridLayout(this);
    mainlayout->setObjectName(QStringLiteral("layout"));
    mainlayout->setContentsMargins(10,10,10,10);
    mainlayout->setColumnMinimumWidth(1,85);
    mainlayout->setColumnMinimumWidth(5,85);
    mainlayout->setSpacing(0);
    mainlayout->setRowMinimumHeight(1,85);
    mainlayout->setRowStretch(1,1);
    mainlayout->setColumnStretch(1,1);
    //layout->setMinimumSize(500,500);
    //layout->setMaximumSize(850,850);
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
            square->setMinimumSize(85,85);
            square->setMaximumSize(85,85);
            if((i+j)%2==1) {
               icon = new QIcon("caseNoire.png");
            }
            else{
                icon = new QIcon("caseBlanche.png");
            }
            square->setIcon(*icon);
            square->setIconSize(QSize(85,85));
            square->show();
            mainlayout->addWidget(square,i,j, Qt::AlignCenter);
            square->setPos(i,j);
            connect(square, SIGNAL(clicked(int x, int y)), this, SLOT(clickedDamier(int x, int y)));
            mysquares.push_back(square);
            j=j+1;
        }
        i=i+1;
    }
   /*setSquare(1,1,"caseBlanche.png");*/
}

void Damier::clickedDamier(int x, int y){
    emit clicked(x,y);
}
/*void Damier::setSquare(int i,int j, QString nameIcon)
{
    icon = new QIcon(nameIcon);
    Square *square;
    QWidget *lay;
    lay =mainlayout->itemAtPosition(i,j)->widget();
    square = mainlayout->takeAt(mainlayout->indexOf(lay));

}*/
