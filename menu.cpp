#include <QtWidgets>
#include <iostream>
#include "menu.h"

Menu::Menu()
{
    createMenu();
    createHorizontalGroupBox();
    createImage();
   // createFormGroupBox();

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("This widget takes up all the remaining space "
                               "in the top-level layout."));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(gridGroupBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Menu"));
}

void Menu::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void Menu::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;


        buttons[0] = new QPushButton("Play 2 players");
        layout->addWidget(buttons[0]);
        buttons[1] = new QPushButton("Play 1 players(Still in Dev)");
        layout->addWidget(buttons[1]);
        buttons[2] = new QPushButton("Option");
        layout->addWidget(buttons[2]);
        buttons[3] = new QPushButton("???");
        buttons[3]->setStyleSheet("background-image: url('buttonRed.png');" );
        layout->addWidget(buttons[3]);
    horizontalGroupBox->setLayout(layout);
    connect(buttons[3], SIGNAL(clicked()), qApp, SLOT(quit()));
}

void Menu::createImage()
{
    gridGroupBox = new QGroupBox(tr("The Board"));
    QGridLayout *layout = new QGridLayout;
    QLabel  *label_img  = new QLabel();
    QPixmap *pixmap_img = new QPixmap("checkersImg.jpg");
         label_img->setPixmap(*pixmap_img);

    layout->addWidget(label_img);
    gridGroupBox->setLayout(layout);
   // QLabel *label = new QLabel(this);
    //label->setPixmap(QPixmap("checkersImg.jpg"));
    //gridGroupBox->setVisible(label);
}
