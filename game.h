#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "ball.h"
#include "bat.h"
#include "brick.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Bat *bat;
    Ball *ball;
    Brick *brick;

};

#endif // GAME_H
