#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "bat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a new scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create an item to add to the scene
    Bat *bat = new Bat();
    bat->setRect(0,0,100,100);

    //adding bat to the scene
    scene->addItem(bat);

    QGraphicsView *view  = new QGraphicsView(scene);
    view->show();




    return a.exec();
}
