#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
#include <stack>
#include <iostream>
#include <QList>

class Health : public QGraphicsTextItem
{

public:
    Health(QGraphicsItem * parent=0);
    void increase();
    void decrease();
    int getHealth();
    void createHealth();

private:
    int health;
    int *healthBars ;
    bool isHealthCreated = false;
    QGraphicsPixmapItem *healthBar;
    QList<QGraphicsPixmapItem* >healthBarItems;
};


#endif // HEALTH_H
