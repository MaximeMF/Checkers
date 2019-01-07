#ifndef KING_H
#define KING_H
#include "piece.h"

/**
 * @brief La classe King représente une dame.
 */
class King : public Piece
{

public:

    /**
     * @brief King permet de construire une nouvelle dame.
     * @param c la couleur de la dame
     */
    King(Color c);
};

#endif // KING_H
