#include "bat.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "brick.h"

Bat::Bat(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    perPixel = 10;
    setPixmap(QPixmap(":/images/Res/Images/Playground/Bat.png"));
}

void Bat::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "pressed";
    if(event->key() == Qt::Key_Left){
        moveBatLeft();
    }

    else if(event->key() == Qt::Key_Right){
        moveBatRight();
    }
}


void Bat::spawn()
{
    Brick *brick = new Brick();
    scene()->addItem(brick);

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
