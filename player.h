#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"

/**
 * @brief La classe Player représente un joueur.
 */
class Player
{

public:

    /**
     * @brief Player permet de construire un joueur.
     * @param c la couleur du joueur
     */
    Player(Color);

    /**
     * @brief getColor permet de récupérer la couleur du joueur.
     * @return la couleur du joueur
     */
    Color getColor() const;

    /**
     * @brief getPiecesNumber permet de récupérer le nombre de pièces restantes du joueur.
     * @return
     */
    int getPiecesNumber() const;

    /**
     * @brief operator -- permet de diminuer de 1 le nombre de pièces d'un joueur.
     * @return le nombre de pièces restantes d'un joueur après décrémentation
     */
    int operator--();

    /**
     * @brief operator -- permet de diminuer de 1 le nombre de pièces d'un joueur.
     * @return le nombre de pièces restantes d'un joueur avant décrémentation
     */
    int operator--(int);

private:

    /**
     * @brief COLOR La couleur du joueur.
     */
    const Color COLOR;

    /**
     * @brief piecesNumber Le nombre de pièces restantes d'un joueur.
     */
    int piecesNumber;
};

#endif // PLAYER_H
