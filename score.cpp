#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize score to 0
    score = 0;

    //draw the tet
    setPlainText(QString("Score ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("DigifaceWide",14));

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
