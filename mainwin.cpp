#include "mainwin.h"

#include "mainwin.h"

#include <QtWidgets>

//*********************************************************************************************************

mainwin::mainwin(QWidget *parent) :

   QMainWindow(parent),

   ui(new Ui::mainwin)

{

   ui->setupUi(this);

  signalMapper = new QSignalMapper(this);

   QObject::connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(boutonclic(int)));



   for(int i = 0; i < 100; i++)

       {

        mesBoutons.append(new QPushButton("", this));

       mesBoutons[i]->setMinimumWidth(40);

       mesBoutons[i]->setMinimumHeight(40);

       signalMapper->setMapping(mesBoutons[i],i);

       QObject::connect(mesBoutons[i], SIGNAL(clicked()), signalMapper, SLOT(map() ));

       }

   for(int i = 0; i < 100; i++)

       {

        ui->gridLayout->addWidget(mesBoutons.at(i),i/10,i%10);

        }

}

//********************************************************************************************************

void mainwin::boutonclic(int num)

{

   QString texte;

   texte="Touche "+QString::number(num)+" appuyée";

 QMessageBox::information(this,"Information",texte);

}

//*********************************************************************************************************

mainwin::~mainwin()

{

   delete ui;

}
