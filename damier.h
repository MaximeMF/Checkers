#ifndef DAMIER_H
#define DAMIER_H
#include <QDialog>
#include <QtWidgets>
#include <vector>
#include "square.h"
#include "ui_mainwindow.h"
#include "scorewidget.h"


using namespace std;

/**
 * @brief La classe Damier représente la partie graphique de l'application.
 */
class Damier : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Damier construit un damier graphique avec lequel les utilisateurs peuvent interagir.
     */
    Damier();

    /**
     * @brief setSquare permet de modifier l'icone d'une des cases du damier.
     * @param i la position sur l'axe des abscisses
     * @param j la position sur l'axe des ordonnées
     * @param iconName le nom de l'image (en chaine de caractères) qui va servir d'icone.
     */
    void setSquare(int i, int j, QString iconName);

    /**
     * @brief setScores permet de mettre à jour les scores.
     * @param p1 un entier représentant le score du joueur 1
     * @param p2 un entier représentant le score du joueur 2
     */
    void setScores(int p1, int p2);

public slots:

    /**
     * @brief clickedDamier est appelé lorsqu'un bouton représentant les cases du damier est cliqué.
     * @param x la position sur l'axe des abscisses du bouton cliqué
     * @param y la position sur l'axe des ordonnées du bouton cliqué
     */
    void clickedDamier(int x, int y);

signals:

    /**
     * @brief clicked est un signal émis lorsqu'un des boutons représentant les cases du damier est cliqué.
     * @param x la position sur l'axe des abscisses du bouton cliqué
     * @param yla position sur l'axe des ordonnées du bouton cliqué
     */
    void clicked(int x, int y);

private:

    /**
     * @brief icon va servir pour manipuler les icones des boutons/cases du damier.
     */
    QIcon *icon;

    /**
     * @brief createBoard initialise le damier.
     */
    void createBoard();

    /**
     * @brief mainlayout est la grille contenant les cases du damier.
     */
    QGridLayout *mainlayout;

    /**
     * @brief fenetre est le layout principal de la fenetre.
     */
    QVBoxLayout *fenetre;

    /**
     * @brief mysquares permet de garder l'adressage des squares pour pouvoir les supprimer si besoin.
     */
    vector<Square*> mysquares;

    /**
     * @brief scoreWidget est un widget contenant la barre des scores.
     */
    ScoreWidget *scoreWidget;
};

#endif // DAMIER_H
