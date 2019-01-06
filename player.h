#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

class Player
{
public:
    Player(Color);
    Color getColor() const;
    int getPiecesNumber() const;
    int operator--();
private:
    const Color COLOR;
    int piecesNumber;
};

#endif // PLAYER_H
