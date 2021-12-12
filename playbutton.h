#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>

#include "game.h"

class PlayButton: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PlayButton(QGraphicsItem *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLAYBUTTON_H
