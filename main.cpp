#include "mainwindow.h"
#include <QApplication>
#include "checkerboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Checkerboard c;

    return a.exec();
}
