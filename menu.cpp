#include "menu.h"
#include "game.h"
#include "playbutton.h"

extern Game *game;

Menu::Menu(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setImages();

    setPixmap(*menuBackgroundImage);
    setPos(0,0);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(createMenu()));
    timer->start(2);

    //QGraphicsPixmapItem *playButton = new QGraphicsPixmapItem();
    //playButton->setPixmap(*playButtonImage);
    //scene()->addItem(playButton);

}


void Menu::createMenu()
{
    if (isMenuCreated) return;

    PlayButton *playButtonn = new PlayButton();
    playButtonn->setPos( game->screenWidth/2 - playButtonn->boundingRect().width()*0.5,
                         game->screenHeight/1.7 );
    scene()->addItem(playButtonn);

    //isMenuCreated = true;
    timer->stop();
}


void Menu::setImages()
{
    menuBackgroundImage = new QPixmap(":/images/Res/Images/Menu/Menu_BG.png");
}

