#ifndef BAT_H
#define BAT_H
#include <QGraphicsRectItem>
#include <QObject>

class Bat: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();

private:
    void moveBatLeft();
    void moveBatRight();
};

#endif // BAT_H
