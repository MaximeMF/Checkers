#ifndef SQUARE_H
#define SQUARE_H
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>

/**
 * @brief La classe Square représente une case du damier.
 */
class Square : public QPushButton
{
    Q_OBJECT

public:

    /**
     * @brief posX la position en x de la case.
     */
    int posX;

    /**
     * @brief posY la position en y de la case.
     */
    int posY;

    /**
     * @brief Square Construit la case.
     * @param parent le QWidget parent
     * @param posX la position en x
     * @param posY la position en y
     */
    Square(QWidget* parent, int posX=-1, int posY=-1);

    /**
     * @brief ~Square détruit la case.
     */
    ~Square();

    /**
     * @brief setPos Détermine la position d'une case.
     * @param x la position en x
     * @param y la position en y
     */
    void setPos(int x, int y);

signals:

    /**
     * @brief clicked est un signal émis lorsque la case est cliquée.
     * @param x la position en x de la case
     * @param y la position en y de la case
     */
    void clicked(int posX, int posY);

protected:

    /**
     * @brief mousePressEvent L'événèment déclenché lorsque la case est cliquée.
     * @param event l'évènement
     */
    void mousePressEvent(QMouseEvent* event);

};

#endif // SQUARE_H
