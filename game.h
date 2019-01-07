#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <QtWidgets>
#include <vector>
#include "player.h"
#include "checkerboard.h"
#include "damier.h"



class Game : public QObject
{
    Q_OBJECT

    public:
        Game(Damier *damier);
        void play();

    public slots:
        void clicked(int x, int y);
        void clicked2(int x, int y);

    private:
        Player player1;
        Player player2;
        Player* currentPlayer;
        bool was_clicked;
        int clickPosX;
        int clickPosY;
        Checkerboard checkerboard;
        Damier *damier;
        void changeTurn();
        void initialisation();
};

#endif // GAME_H
