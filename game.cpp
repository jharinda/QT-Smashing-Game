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

    setGameScene();
    setGameView();

    //set image files
    setPixmaps();

    createBat();
    createBall();
    createBrick(3000);
    createScore();

}

//Spawn Brick SLOT
void Game::spawnBrick()
{
    Brick *brick = new Brick();
    scene->addItem(brick);
    brick->setPixmap(*brickImage);
}

void Game::setPixmaps()
{
    batImage = new QPixmap(":/images/Res/Images/Playground/Bat.png");
    ballImage = new QPixmap(":/images/Res/Images/Playground/Ball.png");
    brickImage = new QPixmap(":/images/Res/Images/Playground/Brick.png");
}

void Game::createBat()
{

    bat = new Bat();
    //set image to the bat
    bat->setPixmap(*batImage);

    //setting bat position
    bat->setPos( view->width()/2 - (bat->pixmap().width()/2),
                 view->height() - bat->pixmap().height()*1.5);

    //setting focus to the bat
    bat->setFlag(QGraphicsItem::ItemIsFocusable);
    bat->setFocus();

    //adding bat to the scene
    scene->addItem(bat);
}

void Game::createBall()
{
    ball = new Ball(10);
    ball->setPos(0 ,0);
    ball->setPixmap(*ballImage);
    scene->addItem(ball);

    QTimer *ballTimeout = new QTimer();
    connect(ballTimeout,SIGNAL(timeout()),ball,SLOT(move()));

    ballTimeout->start(33);
}

void Game::createBrick(int spawnTimeout)
{
    //Generate Brick
    QTimer *brickGenerator = new QTimer();
    connect( brickGenerator,SIGNAL(timeout()),this,
             SLOT(spawnBrick()));
    brickGenerator->start(spawnTimeout);
}

void Game::createScore()
{
    //create the score
    score = new Score();
    score->setPos(score->boundingRect().width() / 4,
                  view->height() - score->boundingRect().height() - 3);

    scene->addItem(score);
}

void Game::setGameView()
{
    //initialize the view
    view  = new QGraphicsView(scene);

    //hiding scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting fixed size to the view
    view->setFixedSize(screenWidth, screenHeight);
    view->show();
}

void Game::setGameScene()
{
    //initialize the new scene
    scene = new QGraphicsScene();

    //set game background
    scene->setBackgroundBrush(QPixmap(":/images/Res/Images/Playground/Background.png"));
    scene->setSceneRect(0,0,screenWidth, screenHeight);
}
