#ifndef BAT_H
#define BAT_H
#include <QGraphicsRectItem>
#include <QObject>

class Bat: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event);

private:
    void moveBatLeft();
    void moveBatRight();
};

#endif // BAT_H
