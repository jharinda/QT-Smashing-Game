#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Brick: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brick(QGraphicsItem *parent = 0);

public slots:
    void checkCollision();
};

#endif // BRICK_H
