#ifndef DAMIER_H
#define DAMIER_H
#include <QDialog>
#include <QtWidgets>
#include <vector>
#include "square.h"
#include "ui_mainwindow.h"

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

private:
    void createBoard();


    QMenu *fileMenu;
    QAction *exitAction;
    QGridLayout *mainlayout;
    vector<Square*> mysquares;
    QHBoxLayout *layout;
};

#endif // DAMIER_H
