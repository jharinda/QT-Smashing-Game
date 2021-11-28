#ifndef BAT_H
#define BAT_H
#include <QGraphicsRectItem>

class Bat:public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event);

};

#endif // BAT_H
