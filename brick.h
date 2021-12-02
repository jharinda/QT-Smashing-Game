#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Brick: public QObject, public QGraphicsPixmapItem
{
public:
    Brick(QGraphicsItem *parent = 0);
};

#endif // BRICK_H
