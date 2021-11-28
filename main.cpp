#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "bat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a new scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create an item to add to the scene
    Bat *bat = new Bat();
    bat->setRect(0,0,100,10);

    Ball *ball = new Ball(10,10,20,20,10);


    //adding bat to the scene
    scene->addItem(bat);
    scene->addItem(ball);

    //setting focus to the bat
    bat->setFlag(QGraphicsItem::ItemIsFocusable);
    bat->setFocus();

    QGraphicsView *view  = new QGraphicsView(scene);

    //hiding scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting fixed size to the view
    view->setFixedSize(400,600);
    scene->setSceneRect(0,0,400,600);

    view->show();

    //setting bat position
    bat->setPos(view->width()/2 - (bat->rect().width()/2),
                view->height() - bat->rect().height()*2);

    return a.exec();
}


