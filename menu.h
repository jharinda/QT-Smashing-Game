#ifndef MENU_H
#define MENU_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Menu :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Menu(QGraphicsItem *parent = 0);

public slots:
    void createMenu();

private:
    void setImages();
    QTimer *timer;

    QPixmap *menuBackgroundImage;
    bool isMenuCreated = false;


};

#endif // MENU_H
