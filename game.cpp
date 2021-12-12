#include "game.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 600

Game::Game(QWidget *parent)
{
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;

    //initialize game scene
    setGameScene();

    //initialize game view
    setGameView();

    //set image files
    setPixmaps();

    //add event listener to scene
    scene->installEventFilter(this);

    //create game menu
    createMenu();
}

void Game::createMatch()
{
    createHealthHolder();

    createBat();

    createBall();

    createBrick(3000);

    createScore();

    createHealth();
}

void Game::spawnBrick()
{
    brick = new Brick();

    scene->addItem(brick);

    brick->setPixmap(*brickImage);
}

void Game::setPixmaps()
{
    batImage = new QPixmap(":/images/Res/Images/Playground/Bat.png");
    ballImage = new QPixmap(":/images/Res/Images/Playground/Ball.png");
    brickImage = new QPixmap(":/images/Res/Images/Playground/Brick.png");
    healthBarImage = new QPixmap
                            (":/images/Res/Images/Playground/Player_health_holder.png");
    healthHolderImage = new QPixmap
                            (":/images/Res/Images/Playground/Player_health_holder.png");
}

void Game::createMenu()
{
    menu = new Menu();
    scene->addItem(menu);
}

bool Game::eventFilter(QObject *target, QEvent *event){
    if ( target == scene )
        {
            //mouse movement listener to move the bat
            if (event->type() == QEvent::GraphicsSceneMouseMove)
            {
                QGraphicsSceneMouseEvent *mouseEvent
                        = static_cast<QGraphicsSceneMouseEvent *>( event );

                if(bat){
                    int batPosX  = mouseEvent -> scenePos().x()
                            - bat -> boundingRect().width() / 2;

                    //setting bat's X position
                    if(batPosX > 0 && batPosX + bat -> boundingRect().width() < screenWidth){
                            bat -> setX(batPosX);
                        }
                }
            }
        }
    return false;
}


void Game::createBat()
{

    bat = new Bat(20);

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
    //creating and setting the ball speed
    ball = new Ball(-10);

    //setting ball position
    ball->setPos( bat->pos().x() ,
                 screenWidth - ball->boundingRect().height() - 10);

    //set image to the bat
    ball->setPixmap(*ballImage);

    //add ball to the scene
    scene->addItem(ball);

    //add ball to the scene
    ballTimeout = new QTimer();
    connect(ballTimeout,SIGNAL(timeout()),ball,SLOT(move()));

    ballTimeout->start(33);
}

void Game::createBrick(int spawnTimeout)
{
    //Generate Brick
    brickGenerator = new QTimer();

    connect( brickGenerator,SIGNAL(timeout()),this,
             SLOT(spawnBrick()));

    brickGenerator->start(spawnTimeout);
}

void Game::createScore()
{
    score = new Score();

    score->setPos(score->boundingRect().width() / 4,
                  view->height() - score->boundingRect().height() - 3);

    scene->addItem(score);
}

void Game::createHealth()
{
    health = new Health();

    health->setPos(healthHolder->x() - (health->boundingRect().width() + 2),
                   healthHolder->y() -  health->boundingRect().height() * 0.2);

    scene->addItem(health);
}

void Game::createHealthHolder()
{
    //adding health holder
    healthHolder = new QGraphicsPixmapItem();
    //set image
    healthHolder->setPixmap(*healthHolderImage);
    //set position in the scene
    healthHolder->setPos(screenWidth - healthHolder->boundingRect().width()* 1.1,
                         screenHeight - healthHolder->boundingRect().height()* 1.3);
    //add to the scene
    scene->addItem(healthHolder);
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
    //set diamentions
    scene->setSceneRect(0,0,screenWidth, screenHeight);
}
