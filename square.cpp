#include "square.h"
#include <QDebug>
Square::Square(QWidget* parent,int posX, int posY)
    : QPushButton(parent) { this->posX=posX; this->posY=posY;

}

Square::~Square() {}

void Square::mousePressEvent(QMouseEvent* event) {
    printf("t'as bien cliqué le bouton connard \n");
    emit clicked(posX, posY);
    qDebug()<<posX<<posY;

}

void Square::setPos(int x, int y){
    this->posX=x;
    this->posY=y;
}
