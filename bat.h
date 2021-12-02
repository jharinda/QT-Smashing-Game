#ifndef BAT_H
#define BAT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#define RECOIL_X_MAX 20


class Bat: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bat(QGraphicsItem *parent = 0);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();

public:
    void moveBatLeft();
    void moveBatRight();
};

#endif // BAT_H
