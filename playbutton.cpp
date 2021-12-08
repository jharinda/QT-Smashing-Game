#include "playbutton.h"
#include "game.h"
#include <QDebug>
extern Game *game;
PlayButton::PlayButton(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap *playButtonImage = new QPixmap(":/images/Res/Images/Menu/Play_Button.png");

    setPixmap(*playButtonImage);

}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<< "Press 1";
    game->createMatch();
    delete game->menu;
    delete this;
}
