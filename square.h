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


class Square : public QPushButton {

    Q_OBJECT

    public:
        int posX;
        int posY;
        Square(QWidget* parent, int posX=-1, int posY=-1);
        ~Square();

    signals:
        void clicked();

    protected:
        void mousePressEvent(QMouseEvent* event);

};

#endif // SQUARE_H
