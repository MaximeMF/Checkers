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
    Player player1;
    Player player2;
    Checkerboard checkerboard;
};

#endif // GAME_H
