#include "player.h"

Player::Player(Color c) : COLOR(c)
{
    piecesNumber = 20;
}

Color Player::getColor()
{
    return COLOR;
}

int Player::getPiecesNumber()
{
    return piecesNumber;
}
