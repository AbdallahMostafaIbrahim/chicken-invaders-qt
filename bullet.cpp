#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "chick.h"
#include "stats.h"
#include <QMediaPlayer>
#include <QAudioOutput>

#include <QDebug>

Bullet::Bullet(): QGraphicsPixmapItem(),QObject()
 {
    setPixmap(QPixmap(":/img/Images/red_laser.png").scaled(40,40));

    audioOutput = new QAudioOutput();
    soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl("qrc:/sounds/sounds/blaster-2-81267.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    soundEffect->play();

    //connect timer

     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));

     timer->start(50);
}

 void Bullet :: move()
{
     QList<QGraphicsItem *> colliding_items = collidingItems();
     for (int i = 0, n = colliding_items.size(); i < n; ++i){
         if (typeid(*(colliding_items[i])) == typeid(Chick)){
             // increase score
             Stats::increase();
             soundEffect->setSource(QUrl("qrc:/sounds/sounds/chicken-single-alarm-call-6056.mp3"));
             soundEffect->play();

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
