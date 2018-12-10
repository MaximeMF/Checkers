#include "mainwindow.h"
#include <QApplication>
#include "checkerboard.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    Menu menu;
    menu.show();
  //  w.show();
    Checkerboard c;

    return app.exec();
}


