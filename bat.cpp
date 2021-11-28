#include "bat.h"
#include <QKeyEvent>


void Bat::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        setPos(x() - 10, y());
    }

    else if(event->key() == Qt::Key_Right){
        setPos(x() + 10, y());
    }
}
