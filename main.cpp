#include "mainwindow.h"
#include <QApplication>
#include "checkerboard.h"
#include "menu.h"
#include "damier.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
   // Menu menu;
  //  menu.show();
  //  w.show();
    Damier *d = new Damier();
    d->show();
    Checkerboard c;

    return app.exec();
}


