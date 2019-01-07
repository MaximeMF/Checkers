#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

/**
 * @brief La classe ScoreWidget représente un Widget servant à afficher les scores.
 */
class ScoreWidget : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief ScoreWidget construit le panel des scores.
     * @param parent le parent de ce widget
     */
    ScoreWidget(QWidget *parent);

    /**
     * @brief ~ScoreWidget détruit le panneau des scores.
     */
    ~ScoreWidget();

private:

    /**
     * @brief layout le layout contenant les labels.
     */
    QHBoxLayout* layout;

    /**
     * @brief score1 Le label affichant le score du joueur 1.
     */
    QLabel* score1;

    /**
     * @brief score2 Le label affichant le score du joueur 2.
     */
    QLabel* score2;

public slots:

    /**
     * @brief setScore1 définit la valeur à afficher pour le score du premier joueur.
     * @param score le score du joueur 1
     */
    void setScore1(int score);

    /**
     * @brief setScore2 définit la valeur à afficher pour le score du second joueur.
     * @param score le score du joueur 2
     */
    void setScore2(int score);
};

#endif // SCOREWIDGET_H
