#ifndef MENU_H
#define MENU_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Menu :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Menu(QGraphicsItem *parent = 0);
private:
    void setImages();

public slots:
    void createMenu();

private:
    QTimer *timer;
    QPixmap *menuBackgroundImage;
};

#endif // MENU_H
