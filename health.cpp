#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize score to 0
    health = 5;

    //draw the tet
    setPlainText(QString("Health ") + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

}

void Health::increase()
{
    health++;
    setPlainText(QString("Health ") + QString::number(health));
}

void Health::decrease()
{
    health -= 1;
    setPlainText(QString("Health ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
