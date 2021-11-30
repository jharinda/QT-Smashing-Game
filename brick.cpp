#include "brick.h"
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <stdlib.h>

Brick::Brick():QObject(),QGraphicsRectItem()
{
    int random_number = rand() % 500;
    setPos(random_number,100);
    setRect(0,0,100,50);

    //QTimer *timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}
