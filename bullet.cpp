#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "chick.h"

#include <QDebug>

Bullet::Bullet(): QGraphicsPixmapItem(),QObject()
 {
    setPixmap(QPixmap(":/img/Images/red_laser.png").scaled(40,40));

    //connect timer

     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));

     timer->start(50);
}

 void Bullet :: move()
{

    //move up
     setPos(x(),y()-10);
     if (pos().y() + pixmap().height() < 0){
         scene()->removeItem(this);
         delete this;
     }
}
