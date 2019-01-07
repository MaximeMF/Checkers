#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    ScoreWidget(QWidget *parent);
    ~ScoreWidget();
private:
    QHBoxLayout* layout;
    QLabel* score1;
    QLabel* score2;

public slots:
    void setScore1(int score);
    void setScore2(int score);
};
#endif // SCOREWIDGET_H
