#include "playbutton.h"

extern Game *game;

PlayButton::PlayButton(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap *playButtonImage = new QPixmap(":/images/Res/Images/Menu/Play_Button.png");
    setPixmap(*playButtonImage);
}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //create match when play button clicked
    game->createMatch();

    //closing the menu
    delete game->menu;
    delete this;
}
