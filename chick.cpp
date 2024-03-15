#include "chick.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "stats.h"
#include "SpaceShip.h"
#include <QMediaPlayer>
#include <QAudioOutput>


Chick::Chick() : QObject(), QGraphicsPixmapItem()
{
    audioOutput = new QAudioOutput();
    soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl("qrc:/sounds/sounds/chicken-single-alarm-call-6056.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);

    goRight =rand() % 2;
    setPixmap(QPixmap(":/img/Images/chicken.png").scaled(100,100));

    int random_number = rand() % 700;
    setPos(random_number,0);


    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Chick::move(){
    // move enemy down
    if(goRight)
    {
    setPos(x()+2,y()+5);
        if (pos().x() + 100 >= 800)
        goRight = false;
    }
    else
    {
     setPos(x()-2,y()+5);
        if (pos().x() - 100 <= 0)
            goRight = true;
    }

    if (pos().y() + pixmap().height() > scene()->height()){
        Stats::decrease();
        scene()->removeItem(this);
        delete this;
        return;
    }


    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(SpaceShip)){
            soundEffect->play();

            // remove the chick
            scene()->removeItem(this);
            Stats::decrease();
            delete this;
            return;
        }
    }
}

