#include "ball.h"
#include "game.h"

extern Game * game;

Ball::Ball(float speed, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{

    ballHitBat = new QMediaPlayer();
    ballHitBrick = new QMediaPlayer();
    ballHitWall = new QMediaPlayer();
    ballHitBottom = new QMediaPlayer();
    gameLost = new QMediaPlayer();

    ballHitBat->setMedia(QUrl("qrc:/sounds/Res/Sounds/Bat_Hit.wav"));
    ballHitBrick->setMedia(QUrl("qrc:/sounds/Res/Sounds/Brick_Hit.wav"));
    ballHitWall->setMedia(QUrl("qrc:/sounds/Res/Sounds/Wall_Hit.wav"));
    ballHitBottom->setMedia(QUrl("qrc:/sounds/Res/Sounds/Ball_Hit_Bottom.wav"));
    gameLost->setMedia(QUrl("qrc:/sounds/Res/Sounds/Game_Lost.wav"));

    speedY = speed;
    speedX = speedY;

}

void Ball::move(){

    game->health->createHealth();

    //when ball reaches the right
    if(pos().x() + (pixmap().width()) > scene()->width()){
        if(speedX > 0 ){
            speedX *= -1;
        }
        playSound(ballHitWall);
    }

     //when ball reaches the left
    if (pos().x() < 0) {
        if(speedX < 0){
            speedX *= -1;
        }
        playSound(ballHitWall);
    }

    //when ball reaches the bottom
    if ( pos().y() + ( pixmap().height() ) > scene()->height() - 40 ) {
        //invert the speed
        if(speedY > 0){
            speedY *= -1;
        }

        //decrease the score
        game->health->decrease();

        //game over
        if(game->health->getHealth() <= 0){
            playSound(gameLost);

            //reset the game scene
            game->createMenu();
            game->ballTimeout->stop();
            game->brickGenerator->stop();

            delete game->bat;
            game->bat = nullptr;
            delete game->score;
            delete this;
            return;
        }

         playSound(ballHitBottom);
    }

    //when ball reaches the top
    if (pos().y() <= 0) {
        if(speedY < 0){
            speedY *= -1;
        }

        playSound(ballHitWall);
    }

    //move ball through x and y a
    setPos(x() + speedX, y()+ speedY);

    //collision detection
    QList<QGraphicsItem* > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n ; ++i ){

        if(typeid(*(colliding_items[i])) == typeid(Brick)){
            playSound(ballHitBrick);

            int BRICK_WIDTH =  colliding_items[i]-> boundingRect().width();
            int brickX = colliding_items[i]->pos().x();

            if( x() + pixmap().width() > brickX &&
                x() <= brickX + BRICK_WIDTH ){
                speedY *= -1;
            }
            else{
                speedX *= -1;
            }

             game->score->increase();
             delete colliding_items[i];
        }

        else if( typeid(*(colliding_items[i])) == typeid(Bat)){

        playSound(ballHitBat);

        int BAT_WIDTH =  colliding_items[i]->boundingRect().width();
        int batX = colliding_items[i]->pos().x();
        float batHitPos = ( pos().x() - ( batX + BAT_WIDTH / 2)) / (BAT_WIDTH);

        if(speedY >0){
            speedY *= -1;
        }
            speedX = batHitPos * RECOIL_X_MAX;
        }
    }
}

void Ball::playSound(QMediaPlayer *sound)
{
    if (sound->state() == QMediaPlayer::PlayingState){
        sound->setPosition(0);
    }
    else if (sound->state() == QMediaPlayer::StoppedState){
        sound->play();
    }
}

