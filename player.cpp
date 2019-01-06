#include "player.h"

Player::Player(Color c) : COLOR(c)
{
    piecesNumber = 20;
}

Color Player::getColor() const
{
    return COLOR;
}

int Player::getPiecesNumber() const
{
    return piecesNumber;
}
