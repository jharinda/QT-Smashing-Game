#ifndef BALL_H
#define BALL_H
#include <QGraphicsEllipseItem>
#include <QObject>


class Ball: public QObject ,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Ball(float x,float y ,float width,float height,float speed);
public slots:
    void move();

public:
    float speedX;
    float speedY;
};

#endif // BALL_H
