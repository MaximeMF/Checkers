#ifndef MAINWIN_H

#define MAINWIN_H
#include <QMainWindow>

#include <QtWidgets/QMessageBox>

#include <QVector>

#include <QSignalMapper>

#include <QPushButton>

namespace Ui {

class mainwin;

}



class mainwin : public QMainWindow

{

   Q_OBJECT



public:

   explicit mainwin(QWidget *parent = 0);

   ~mainwin();

public slots:

public slots:

   void boutonclic(int num);

private:

   Ui::mainwin *ui;

   QVector<QPushButton*> mesBoutons;

   QSignalMapper *signalMapper;

};



#endif // MAINWIN_H
