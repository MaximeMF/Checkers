#include "square.h"
Square::Square(QWidget* parent,int posX, int posY)
    : QPushButton(parent) { this->posX=posX; this->posY=posY;

}

Square::~Square() {}

void Square::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
