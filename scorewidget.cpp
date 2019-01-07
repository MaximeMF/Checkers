#include "scorewidget.h"
#include <QString>
ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setMargin(0);

    this->score1 = new QLabel("Player 1");
    this->score1->setAlignment(Qt::AlignHCenter);
    this->score2 = new QLabel("Player 2");
    this->score2->setAlignment(Qt::AlignHCenter);

    layout->addWidget(this->score1);
    layout->addWidget(this->score2);
    //this->setStyleSheet("background-color:black;");
}

ScoreWidget::~ScoreWidget() {
    delete layout;
    delete score1;
    delete score2;
}

void ScoreWidget::setScore1(int score) {
    this->score1->setText("Player 1:  " + QString::number(score));
}

void ScoreWidget::setScore2(int score) {
    this->score2->setText("Player 2:  " + QString::number(score));
}

void setScore1(int score);
