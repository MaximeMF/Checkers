#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

class Player
{
public:
    Player(Color);
    Color getColor();
    int getPiecesNumber();
private:
    const Color COLOR;
    int piecesNumber;
};

#endif // PLAYER_H
