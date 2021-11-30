#include "ball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "bat.h"
#include <QList>

#include "brick.h"

Ball::Ball(float x,float y ,float width,float height,float speed)
{
    QRectF rectangle(x,y, width, height);
    setRect(rectangle);

    speedY = speed;
    speedX = speedY;

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(33);
}

void Ball::move(){

    QList<QGraphicsItem* > colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n ; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Brick)){
            scene()->removeItem(colliding_items[i]);
            qDebug() << "brick removed";
        }
    }


    //when ball reaches the right
    if(pos().x() + (rect().width()) * 2 > scene()->width()){
        speedX *= -1;
    }

     //when ball reaches the left
    if (pos().x() < 0) {
        speedX *= -1;

    }

    //when ball reaches the bottom
    if (pos().y() + (rect().height()) > scene()->height()) {
        speedY *= -1;
    }

    //when ball reaches the top
    if (pos().y() < 0) {
        speedY *= -1;
    }

    //move ball through x and y a
    setPos(x() + speedX, y()+ speedY);


}

