#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "ball.h"
#include "bat.h"
#include "brick.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    QGraphicsView *view;
    Bat *bat;
    Ball *ball;
    Brick *brick;
    Score *score;
    Health *health;

    QGraphicsPixmapItem *healthHolder;

    int screenWidth;
    int screenHeight;
private:
    QPixmap *batImage;
    QPixmap *ballImage;
    QPixmap *brickImage;
    QPixmap *healthBarImage;
    QPixmap *healthHolderImage;


public slots:
    void spawnBrick();

private:
    void setPixmaps();

    void createBat();
    void createBall();
    void createBrick(int spawnTimeout);
    void createScore();
    void createHealth();
    void createHealthHolder();

    void setGameView();
    void setGameScene();

};

#endif // GAME_H
