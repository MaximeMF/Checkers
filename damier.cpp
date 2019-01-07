#include <QtWidgets>
#include <iostream>
#include "damier.h"
#include <QDebug>


Damier::Damier() :
QDialog()
{
    //this->setFixedSize(850,850);
    resize(850,850);
   // mainlayout = new Qmainlayout(this);
    fenetre = new QVBoxLayout(this);
    setLayout(fenetre);
    mainlayout = new QGridLayout();
    fenetre->addLayout(mainlayout);
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
     scoreWidget = new ScoreWidget(this);
     fenetre->addWidget(scoreWidget);
     scoreWidget->setScore1(20);
     scoreWidget->setScore2(20);

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
            mainlayout->addWidget(square,j,i, Qt::AlignCenter);
            square->setPos(j,i);
            connect(square, SIGNAL(clicked(int, int)), this, SLOT(clickedDamier(int, int)));
            mysquares.push_back(square);
            j=j+1;

        }
        i=i+1;
    }
   setSquare(1,1,"caseBlanche.png");
}

void Damier::clickedDamier(int x, int y){
    emit clicked(x,y);
}
void Damier::setSquare(int i,int j, QString nameIcon)
{
    icon = new QIcon(nameIcon);
    Square *square;
    square =dynamic_cast<Square*>(mainlayout->itemAtPosition(j,i)->widget());
    QIcon icon2;
    icon2=square->icon();
    square->setIcon(*icon);
    icon2.~QIcon();
}

void Damier::setScores(int p1, int p2){
    scoreWidget->setScore1(p1);
    scoreWidget->setScore2(p2);
}
