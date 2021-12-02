#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include "ball.h"
#include "bat.h"
#include "brick.h"
#include <QDebug>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 600

Game::Game(QWidget *parent)
{
    //create a new scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create an item to add to the scene
    Bat *bat = new Bat();

    Ball *ball = new Ball(0,0,20,20,9);
    ball->setPos(0,0);

    //Brick *brick = new Brick();
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),bat,SLOT(spawn()));

    //create the score
    score = new Score();

    scene->addItem(score);

    //adding bat to the scene
    scene->addItem(bat);
    scene->addItem(ball);

    //setting focus to the bat
    bat->setFlag(QGraphicsItem::ItemIsFocusable);
    bat->setFocus();

    QGraphicsView *view  = new QGraphicsView(scene);

    //hiding scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting fixed size to the view
    view->setFixedSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    scene->setSceneRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

    view->show();

    //setting bat position
    bat->setPos(view->width()/2 - (bat->pixmap().width()/2),
                view->height() - bat->pixmap().height()*1.5);

     score->setPos(score->boundingRect().width() / 4,
                   view->height() - score->boundingRect().height() - 3);


    scene->setBackgroundBrush(QPixmap(":/images/Res/Images/Playground/Background.png"));

    timer->start(2000);
}
