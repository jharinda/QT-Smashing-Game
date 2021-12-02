#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include "ball.h"
#include "bat.h"
#include "brick.h"
#include <QDebug>
#include <QPixmap>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 600

Game::Game(QWidget *parent)
{
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;

    //initialize the new scene
    scene = new QGraphicsScene();

    view  = new QGraphicsView(scene);

    //create an item to add to the scene
    batImage = new QPixmap(":/images/Res/Images/Playground/Bat.png");
    ballImage = new QPixmap(":/images/Res/Images/Playground/Ball.png");
    brickImage = new QPixmap(":/images/Res/Images/Playground/Brick.png");

    Bat *bat = new Bat();
    bat->setPixmap(*batImage);

    Ball *ball = new Ball(10);
    ball->setPos(0,0);
    ball->setPixmap(*ballImage);

    //create the score
    score = new Score();
    scene->addItem(score);

    //adding bat to the scene
    scene->addItem(bat);
    scene->addItem(ball);

    //setting focus to the bat
    bat->setFlag(QGraphicsItem::ItemIsFocusable);
    bat->setFocus();

    //Generate Brick
    QTimer *brickGenerator = new QTimer();
    QObject::connect( brickGenerator,SIGNAL(timeout()),this,
                     SLOT(spawnBrick()));
    brickGenerator->start(3000);



    //hiding scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting fixed size to the view
    view->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    scene->setSceneRect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT);

    view->show();

    //setting bat position
    bat->setPos(view->width()/2 - (bat->pixmap().width()/2),
                view->height() - bat->pixmap().height()*1.5);

    score->setPos(score->boundingRect().width() / 4,
                  view->height() - score->boundingRect().height() - 3);

    //set game background
    scene->setBackgroundBrush(QPixmap(":/images/Res/Images/Playground/Background.png"));
}

//Spawn Brick SLOT
void Game::spawnBrick()
{
    qDebug() << "spawn";
    Brick *brick = new Brick();
    scene->addItem(brick);
    brick->setPixmap(*brickImage);

}
