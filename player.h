#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

class Player
{
public:
    Player(Color);
    Color getColor() const;
    int getPiecesNumber() const;
private:
    const Color COLOR;
    int piecesNumber;
};

#endif // PLAYER_H
