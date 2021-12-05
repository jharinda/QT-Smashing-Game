#include "brick.h"
#include <QGraphicsScene>
#include <QList>
#include <QPointF>
#include <QTimer>
#include <stdlib.h>
#include "game.h"

extern Game * game;

Brick::Brick(QGraphicsItem *parent):QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/Res/Images/Playground/Brick.png"));

    int random_posX = rand() % game->screenWidth - pixmap().width();
    int random_posY = rand() % game->screenHeight  - game->screenHeight / 3;

    if (random_posX < 0){
     random_posX *= -1;
     random_posX += pixmap().height()* 2;
    }

    if (random_posY < 0){
        random_posY *= -1;
        random_posY += pixmap().width();
    }

    setPos(random_posX, random_posY);
    QTimer *timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(checkCollision()));
    timer->start(1);

}

void Brick::checkCollision()
{

    QList<QGraphicsItem* > colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n ; ++i){

        // Check brick overlapping
        if(typeid(*(colliding_items[i])) == typeid(Brick)){
             scene()->removeItem(colliding_items[i]);
             delete colliding_items[i];

        }
    }

}


