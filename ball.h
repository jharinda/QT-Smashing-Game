#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QMediaPlayer>
#include <QObject>

class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(float speed,QGraphicsItem *parent = 0);

private:
    void playSound(QMediaPlayer *sound);

public slots:
    void move();

private:
    float speedX;
    float speedY;

    QMediaPlayer * ballHitWall;
    QMediaPlayer * ballHitBat;
    QMediaPlayer * ballHitBrick;
    QMediaPlayer * ballHitBottom;
    QMediaPlayer * gameLost;
};

#endif // BALL_H
