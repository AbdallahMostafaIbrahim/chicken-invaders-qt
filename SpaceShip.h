#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpaceShip();
    void keyPressEvent(QKeyEvent * event);
};

#endif // SPACESHIP_H
