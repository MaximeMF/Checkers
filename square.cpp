#include "square.h"
Square::Square(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

Square::~Square() {}

void Square::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
