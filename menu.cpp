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

        buttons = new QPushButton("Play 2 players");
        layout->addWidget(buttons);
        mapButtons.insert(pair<int, QPushButton*>(0, buttons));
        buttons = new QPushButton("Play 1 players(Still in Dev)");
        layout->addWidget(buttons);
        mapButtons.insert(pair<int, QPushButton*>(1, buttons));
        buttons = new QPushButton("Option(Still in dev");
        layout->addWidget(buttons);
        mapButtons.insert(pair<int, QPushButton*>(2, buttons));
        buttons = new QPushButton("???(Still in dev)");
        layout->addWidget(buttons);
        mapButtons.insert(pair<int, QPushButton*>(3, buttons));
        horizontalGroupBox->setLayout(layout);
        connect(mapButtons.find(3)->second, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(mapButtons.find(0)->second, SIGNAL(clicked()), this, SLOT(playDamier()));
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

void Menu::playDamier()
{

    damier = new Damier();
    damier->show();
    game = new Game(damier);
    game->play();
}
