#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <QtWidgets>
#include <vector>
#include "player.h"
#include "checkerboard.h"
#include "damier.h"


/**
 * @brief The Game class permet de relier la logique au graphisme
 */
class Game : public QObject
{
    Q_OBJECT

    public:
    /**
         * @brief Game construit une partie.
         * @param damier le damier qui sera utilisé par la classe Game pour gérer la partie graphique
         */
        Game(Damier *damier);

        /**
         * @brief play lance une partie
         */
        void play();

    public slots:
        /**
         * @brief clicked gère la liaison logique/graphique lorsqu'un utilisateur choisit un pion.
         * @param x La position de la pièce en x
         * @param y La position de la pièce en y
         */
        void clicked(int x, int y);

        /**
         * @brief clicked2 gère la liaison logique/graphique lorsqu'un utilisateur choisit une action à effectuer.
         * @param x La position de l'action en x.
         * @param y La position de l'action en y.
         */
        void clicked2(int x, int y);

    private:
        /**
         * @brief player1 Le joueur 1.
         */
        Player player1;

        /**
         * @brief player2 Le joueur 2.
         */
        Player player2;

        /**
         * @brief currentPlayer le joueur à qui c'est le tour de jouer
         */
        Player* currentPlayer;

        /**
         * @brief clickPosX la position de la pièce selectionnée en x
         */
        int clickPosX;

        /**
         * @brief clickPosY la position de la pièce selectionnée en y
         */
        int clickPosY;

        /**
         * @brief checkerboard Déclaration d'un board logique
         */
        Checkerboard checkerboard;

        /**
         * @brief damier Déclaration d'un damier logique
         */
        Damier *damier;

        /**
         * @brief changeTurn change le 'currentPlayer'
         */
        void changeTurn();

};

#endif // GAME_H
