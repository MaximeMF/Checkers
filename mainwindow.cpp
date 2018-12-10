#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), 
       ui(new Ui::MainWindow)
    {
       ui->setupUi(this);
 /*      scene = new QGraphicsScene(this);
       ui->graphicsView->setScene(scene);
       fond = scene->addPixmap(QPixmap("backgroundBoard.png"));*/
       //damier=fond;
     //  bouton1 = new QPushButton("quit",this);
       //layout1 = new QGridLayout;
       //layout1->addWidget(damier);

    }


MainWindow::~MainWindow()
{
    delete ui;
}
