#include "SpaceShip.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QUrl>


SpaceShip::SpaceShip() : QGraphicsPixmapItem(),QObject() //: QGraphicsPixmapItem(QPixmap(":/img/Images/chicken.png").scaled(100,100))
{
    setPixmap(QPixmap(":/img/Images/ship.png").scaled(100,100));

}

 void SpaceShip :: keyPressEvent(QKeyEvent * event)
{
     if(event->key() == Qt::Key_Left)
    {if (pos().x() > 0)
            setPos(x()-10,y());
}

else if (event->key() == Qt::Key_Right){
    if (pos().x() + 100 < 800)
        setPos(x()+10,y());
}

else if (event->key() == Qt::Key_Space){
    // create a bullet
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+32,y());
    scene()->addItem(bullet);
    QMediaPlayer* effect = new QMediaPlayer;
    effect->setSource(QUrl("qrc:/sounds/sounds/blaster-2-81267.mp3"));
    effect->play();
}

else if (event->key() == Qt::Key_Up){
    if (pos().y() > 0)
        setPos(x(),y()-10);
}

else if (event->key() == Qt::Key_Down){
    if (pos().y() +100 < 600)
        setPos(x(),y()+10);
}
 }



