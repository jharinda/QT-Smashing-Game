#include "ball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "bat.h"

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

    //when ball reaches the right
    if(x() + (rect().width()) * 2 > scene()->width()){
        speedX *= -1;
    }

     //when ball reaches the left
    if (x() < 0) {
        speedX *= -1;

    }

    //when ball reaches the bottom
    if (y() + (rect().height()) * 2 >= scene()->height()) {
        speedY *= -1;
    }

    //when ball reaches the top
    if (y() < 0) {
        speedY *= -1;
    }

    //move ball through x and y a
    setPos(x() + speedX, y()+ speedY);


}

