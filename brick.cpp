#include "brick.h"
#include <QGraphicsScene>
#include <QList>
#include <QPointF>
#include <QTimer>
#include <stdlib.h>
#include "game.h"

extern Game * game;

Brick::Brick(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/Res/Images/Playground/Brick.png"));

    int random_number = rand() % game->screenWidth - pixmap().width();
    setPos(random_number,random_number);


    //QTimer *timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}
