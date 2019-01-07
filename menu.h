#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "damier.h"
#include "game.h"
#include <QMessageBox>
#include<array>
#include<tuple>
#include <map>


/**
 * @brief The Menu class est une fenêtre affichant un menu permettant de lancer le jeu.
 */
class Menu : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Menu construit une fenetre Menu
     */
    Menu();
public slots :
    /**
     * @brief playDamier Lance le jeu de dame.
     */
    void playDamier();
private:

    /**
     * @brief createMenu crée un menu
     */
    void createMenu();
    /**
     * @brief createHorizontalGroupBox crée un layout permettant de placer des widgets/layouts/items/etc horizontalement les uns à la suite des autres.
     */
    void createHorizontalGroupBox();

    /**
     * @brief createImage Crée l'image d'un damier de jeu de dame.
     */
    void createImage();
    /**
     * @brief damier un pointeur de Damier
     */
    Damier *damier;
    /**
     * @brief game un pointeur de Game
     */
    Game *game;


    /**
     * @brief menuBar Unebarre de menu
     */
    QMenuBar *menuBar;

    /**
     * @brief horizontalGroupBox un pointeur de layout QGroupBox
     */
    QGroupBox *horizontalGroupBox;

    /**
     * @brief gridGroupBox un pointeur de layout QGridGroupBox
     */
    QGroupBox *gridGroupBox;

    /**
     * @brief buttons pointe sur des boutons
     */
    QPushButton *buttons;

    /**
     * @brief mapButtons stock des boutons (utilisée pour répondre à l'exigence 'STL')
     */
    std::map<int, QPushButton*> mapButtons;

    /**
     * @brief fileMenu l'onglet file du menu
     */
    QMenu *fileMenu;

    /**
     * @brief exitAction action de quitter la fenêtre et donc le programme.
     */
    QAction *exitAction;
};

#endif // MENU_H
