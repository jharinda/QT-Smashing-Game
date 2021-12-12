#ifndef BAT_H
#define BAT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

#include <QTimer>
#include <QGraphicsScene>
#include <QList>


#define RECOIL_X_MAX 20


class Bat: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bat(int keySensitivity, QGraphicsItem *parent = 0);

private:
    int perPixel;
    void moveBatLeft();
    void moveBatRight();
    void keyPressEvent(QKeyEvent *event);
};

#endif // BAT_H
