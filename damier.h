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
<<<<<<< HEAD
    QGridLayout *mainlayout;
    vector<Square*> mysquares;
=======
    QHBoxLayout *layout;
>>>>>>> e843a57bdef8ad7e164af1829a698dcca97b0677
};

#endif // DAMIER_H
