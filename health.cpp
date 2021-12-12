#include "health.h"
#include "game.h"

extern Game *game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    health = 5;

    //draw the text
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
    if (healthBarItems.length()) {
        scene()->removeItem(healthBarItems.last());
        delete healthBarItems.last();
        healthBarItems.removeLast();
        health --;
    }

}

int Health::getHealth()
{
    return health;
}

void Health::createHealth()
{
    if (isHealthCreated) return;
    for (int i = 0; i < health; ++i ){
        healthBar = new QGraphicsPixmapItem();
        healthBar->setPixmap(QPixmap(":/images/Res/Images/Playground/Health_bar.png"));

        if(healthBarItems.empty()){
            healthBar->setPos(game->healthHolder->x() + 10,
                               game->healthHolder->y() + 4);
        }else{
            healthBar->setPos( healthBarItems.last()->pos().x() + healthBar->boundingRect().width(),
                                healthBarItems.last()->pos().y());
        }

        healthBarItems.append(healthBar);
        scene()->addItem(healthBarItems[i]);
        isHealthCreated = true;
    }
}
