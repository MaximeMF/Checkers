#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "damier.h"
#include "game.h"
#include <QMessageBox>
#include<array>
#include<tuple>
#include <map>

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;

class Menu : public QDialog
{
    Q_OBJECT

public:
    Menu();
public slots :
    void playDamier();
private:
    void createMenu();
    void createHorizontalGroupBox();
    void createImage();
    void createFormGroupBox();
    Damier *damier;
    Game *game;

    enum { NumGridRows = 3, NumButtons = 4 };

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons;
    std::map<int, QPushButton*> mapButtons;
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAction;
};

#endif // MENU_H
