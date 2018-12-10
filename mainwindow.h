#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGridLayout *layout1;
    QPushButton *bouton1;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *fond;
    QWidget *damier;
};

#endif // MAINWINDOW_H
