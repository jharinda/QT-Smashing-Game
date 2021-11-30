#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>
#include <QObject>

class Brick: public QObject, public QGraphicsRectItem
{
public:
    Brick();
};

#endif // BRICK_H
