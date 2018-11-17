#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

class Player
{
public:
    Player(Color);
    Color getColor();
    int getScore();
private:
    const Color COLOR;
    int score;
};

#endif // PLAYER_H
