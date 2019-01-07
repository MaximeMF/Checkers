#ifndef DAMIER_H
#define DAMIER_H
#include <QDialog>
#include <QtWidgets>
#include <vector>
#include "square.h"
#include "ui_mainwindow.h"
#include "scorewidget.h"

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;

using namespace std;

class Damier : public QDialog
{
    Q_OBJECT

public:
    Damier();
    Square getSquare();
    void setSquare(int i, int j, QString iconName);
    void setScores(int p1, int p2);

public slots:
    void clickedDamier(int x, int y);

signals:
    void clicked(int x, int y);

private:
    QIcon *icon;
    void createBoard();


    QMenu *fileMenu;
    QAction *exitAction;
    QGridLayout *mainlayout;
    QVBoxLayout *fenetre;
    vector<Square*> mysquares;
    QHBoxLayout *layout;
    ScoreWidget *scoreWidget;
};

#endif // DAMIER_H
