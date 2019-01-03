#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <QtWidgets>
#include <vector>
#include "player.h"
#include "checkerboard.h"
#include "damier.h"

class Game
{
    public:
        Game();
        void play();

    public slots:
        void clicked(int x, int y);

    private:
        const Player player1;
        const Player player2;
        const Player* currentPlayer;
        boolean was_clicked;
        int clickPosX;
        int clickPosY;
        Checkerboard checkerboard;
        Damier damier;
        void changeTurn();
        void initialisation();
};

#endif // GAME_H
