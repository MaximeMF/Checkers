#ifndef DAMIER_H
#define DAMIER_H
#include <QDialog>
#include <QtWidgets>

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;

class Damier : public QMainWindow
{
    Q_OBJECT

public:
    Damier();

private:
    void createBoard();


    QMenu *fileMenu;
    QAction *exitAction;
    QHBoxLayout *layout;
};

#endif // DAMIER_H
