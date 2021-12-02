#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QMediaPlayer>
#include <QObject>

class Ball: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(float x, float y, float width, float height, float speed,QGraphicsItem *parent = 0);

public slots:
    void move();

private:
    float speedX;
    float speedY;

    void playSound(QMediaPlayer *sound);

    QMediaPlayer * ballHitWall;
    QMediaPlayer * ballHitBat;
    QMediaPlayer * ballHitBrick;
};

#endif // BALL_H
