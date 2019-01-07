#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H
#include "piece.h"
#include "color.h"
#include "king.h"

/**
 * @brief La classe Checkerboard représente la partie logique de l'application.
 */
class Checkerboard
{

public:

    /**
     * @brief Checkerboard permet de construire un nouveau damier.
     */
    Checkerboard();

    /**
     * @brief isPiece vérifie si une case contient une pièce ou non.
     * @param x la position en x
     * @param y la position en y
     * @return true si c'est une pièce, false sinon
     */
    bool isPiece(int x, int y);

    /**
     * @brief isKing vérifie si une pièce est une dame ou non.
     * @param x la position en x
     * @param y la position en y
     * @return true si c'est une dame, false sinon
     */
    bool isKing(int x, int y);

    /**
     * @brief canPromote vérifie si une pièce peut être promue en dame.
     * @param x la position en x
     * @param y la position en y
     * @return true si elle peut être promue, false sinon
     */
    bool canPromote(int x, int y);

    /**
     * @brief promotion promeut une pièce en dame.
     * @param x la position en x
     * @param y la position en y
     */
    void promotion(int x, int y);

    /**
     * @brief canMove vérifie si une pièce peut être déplacée sur une autre case.
     * @param x la position de départ en x
     * @param y la position de départ en y
     * @param dx la position d'arrivée en x
     * @param dy la position d'arrivée en y
     * @return true si elle peut être déplacée, false sinon
     */
    bool canMove(int x, int y, int dx, int dy);

    /**
     * @brief move réalise le déplacement d'une pièce d'une case à une autre.
     * @param x la position de départ en x
     * @param y la position de départ en y
     * @param dx la position d'arrivée en x
     * @param dy la position d'arrivée en y
     */
    void move(int x, int y, int dx, int dy);

    /**
     * @brief canRemove vérifie si une pièce peut manger une autre pièce.
     * @param x la position de départ en x
     * @param y la position de départ en y
     * @param dx la position d'arrivée en x
     * @param dy la position d'arrivée en y
     * @param rx la position de la pièce à manger en x
     * @param ry la position de la pièce à manger en y
     * @return true si la pièce peut être mangée, false sinon
     */
    bool canRemove(int x, int y, int dx, int dy, int* rx, int* ry);

    /**
     * @brief remove fait manger une pièce à une autre.
     * @param x la position de départ en x
     * @param y la position de départ en y
     * @param dx la position d'arrivée en x
     * @param dy la position d'arrivée en y
     * @param rx la position de la pièce à manger en x
     * @param ry la position de la pièce à manger en y
     */
    void remove(int x, int y, int dx, int dy, int rx, int ry);

    /**
     * @brief getColorPiece récupère la couleur d'une pièce.
     * @param x la position en x
     * @param y la position en y
     * @return la couleur de la pièce
     */
    Color getColorPiece(int x, int y);

private:

    /**
     * @brief board Un tableau 2D représentant le damier.
     */
    Piece* board[10][10];

    /**
     * @brief init permet d'initialiser le tableau.
     */
    void init();
};

#endif // CHECKERBOARD_H
