#include "health.h"
#include <QFont>
#include <QPixmap>
#include "game.h"


extern Game *game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize score to 0
    health = 5;

    //draw the tet
    setPlainText(QString("Health"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("DigifaceWide", 10));


}

void Health::increase()
{
    health++;
}

void Health::decrease()
{
    scene()->removeItem(array.last());
    delete array.last();
    array.removeLast();

    health --;
}

int Health::getHealth()
{
    return health;
}

void Health::createHealth()
{
    if (isHealthCreated) return;
    for(int i = 0; i < health; ++i ){
        QGraphicsPixmapItem *healthBarr = new QGraphicsPixmapItem();
        healthBarr->setPixmap(QPixmap(":/images/Res/Images/Playground/Health_bar.png"));

        if(array.empty()){
            healthBarr->setPos(game->healthHolder->x() + 10,
                               game->healthHolder->y() + 4);
        }else{
            healthBarr->setPos( array.last()->pos().x() + healthBarr->boundingRect().width(),
                                array.last()->pos().y());
        }

        array.append(healthBarr);
        scene()->addItem(array[i]);
        isHealthCreated = true;
    }

}
