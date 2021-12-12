#include "bat.h"

Bat::Bat(int keySensitivity,QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    perPixel = keySensitivity;
}

void Bat::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        moveBatLeft();
    }

    else if(event->key() == Qt::Key_Right){
        moveBatRight();
    }
}


void Bat::moveBatLeft()
{
    if(x() > 0) {
        setPos(x() - perPixel, y());
    }
}

void Bat::moveBatRight()
{
    if(x() + pixmap().width() < scene() -> width()) {
         setPos(x() + perPixel, y());
    }
}
