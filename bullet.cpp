#include "chick.h"
#include "stats.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>

Bullet::Bullet(): QObject(), QGraphicsPixmapItem(QPixmap(":/img/Images/red_laser.png").scaled(40,40))
{
    audioOutput = new QAudioOutput();
    soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl("qrc:/sounds/sounds/blaster-2-81267.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    soundEffect->play();


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet :: move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        Chick* chick = dynamic_cast<Chick*>(colliding_items[i]);
        if(chick != nullptr)
        {
            Stats::increase();
            soundEffect->setSource(QUrl("qrc:/sounds/sounds/kill.mp3"));
            soundEffect->play();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    setPos(x(),y()-10);
    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
