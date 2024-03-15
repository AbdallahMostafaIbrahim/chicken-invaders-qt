#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include"SpaceShip.h"
#include "stats.h"


class Bullet : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT

public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
