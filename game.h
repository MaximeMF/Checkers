#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "checkerboard.h"

class Game
{
public:
    Game();
    void play();
private:
    const Player player1;
    const Player player2;
    const Player* currentPlayer;
    Checkerboard checkerboard;
    void changeTurn();
};

#endif // GAME_H
