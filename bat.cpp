#include "bat.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "brick.h"
#include <QDebug>

Bat::Bat(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Res/Images/Playground/Bat.png"));
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

void Bat::spawn()
{
    Brick *brick = new Brick();
    scene()->addItem(brick);

}

void Bat::moveBatLeft()
{
    if(x() > 0) {
        setPos(x() - 10, y());
    }
}

void Bat::moveBatRight()
{
    if(x() + pixmap().width() < scene() -> width()) {
         setPos(x() + 10, y());
    }
}
