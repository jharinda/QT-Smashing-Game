#include "bat.h"
#include <QKeyEvent>
#include <QGraphicsScene>

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
    if(x() > 0){
         setPos(x() - 10, y());
    }
}

void Bat::moveBatRight()
{
    if(x() + rect().width() < scene() -> width()) {
         setPos(x() + 10, y());
    }
}
