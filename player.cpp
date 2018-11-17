#include "player.h"

Player::Player(Color c) : COLOR(c)
{
    score = 0;
}

Color Player::getColor()
{
    return COLOR;
}

int Player::getScore()
{
    return score;
}
