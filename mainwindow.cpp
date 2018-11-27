#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), 
       ui(new Ui::MainWindow)
    {
       ui->setupUi(this);
       scene = new QGraphicsScene(this);
       //scene->setSceneRect(QRectF(0,0,400,400));
       ui->graphicsView->setScene(scene);
       fond = scene->addPixmap(QPixmap("backgroundBoard.png"));
    }


MainWindow::~MainWindow()
{
    delete ui;
}
