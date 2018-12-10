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


class Square : public QLabel {

    Q_OBJECT

    public:
        explicit Square(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
        ~Square();

    signals:
        void clicked();

    protected:
        void mousePressEvent(QMouseEvent* event);

};

#endif // SQUARE_H
