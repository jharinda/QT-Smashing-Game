#include "brick.h"
#include "game.h"

extern Game * game;

Brick::Brick(QGraphicsItem *parent):QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/Res/Images/Playground/Brick.png"));
    // get X position within the scene width
    int random_posX = rand() % game->screenWidth - pixmap().width();
    // get Y position within the scene height
    int random_posY = rand() % game->screenHeight  - game->screenHeight / 3;

    //check pos X is outside of the game scene
    if (random_posX < 0){
     random_posX *= -1;
     random_posX += pixmap().height()* 2;
    }

    //check pos Y is outside of the game scene
    if (random_posY < 0){
        random_posY *= -1;
        random_posY += pixmap().width();
    }
    //set the random position
    setPos(random_posX, random_posY);

    QTimer *timer = new QTimer();
    //checking collision of bricks
    connect(timer,SIGNAL(timeout()),this,SLOT(checkCollision()));
    timer->start(1);
}

void Brick::checkCollision()
{
    // List of collided objects
    QList<QGraphicsItem* > colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n ; ++i){

        // Check brick overlapping
        if(typeid(*(colliding_items[i])) == typeid(Brick)){
             scene()->removeItem(colliding_items[i]);
             delete colliding_items[i];

        }
    }

}


