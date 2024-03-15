#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "chick.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include"SpaceShip.h"
#include"stats.h"



=======
#include "stats.h"
>>>>>>> 54cf620bbb013c156f016e4fe90f3770468cac98
=======
>>>>>>> parent of 54cf620 (stats)

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
     //check for collision

     QList<QGraphicsItem *> colliding_items = collidingItems();
     for (int i = 0, n = colliding_items.size(); i < n; ++i){
         if (typeid(*(colliding_items[i])) == typeid(Chick)){
<<<<<<< HEAD
<<<<<<< HEAD
             //increase score
=======
             // increase score
             Stats::increase();
>>>>>>> 54cf620bbb013c156f016e4fe90f3770468cac98

=======
>>>>>>> parent of 54cf620 (stats)
             // remove them both
             scene()->removeItem(colliding_items[i]);
             scene()->removeItem(this);
             // delete them both
             delete colliding_items[i];
             delete this;
             return;
         }
     }
    //move up
     setPos(x(),y()-10);
     if (pos().y() + pixmap().height() < 0){
         scene()->removeItem(this);
         delete this;
     }
}
