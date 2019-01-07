#ifndef PIECE_H
#define PIECE_H
#include "color.h"

/**
 * @brief La classe Piece représente un pion.
 */
class Piece
{

public:

    /**
     * @brief Piece permet de construire une nouvelle pièce.
     * @param c la couleur de la pièce
     */
    Piece(Color);

    /**
     * @brief ~Piece permet de détruire la pièce.
     */
    virtual ~Piece();

    /**
     * @brief getColor permet de récupérer la couleur de la pièce.
     * @return la couleur de la pièce
     */
    Color getColor();

protected:

    /**
     * @brief COLOR La couleur de la pièce.
     */
    const Color COLOR;
};

#endif // PIECE_H
