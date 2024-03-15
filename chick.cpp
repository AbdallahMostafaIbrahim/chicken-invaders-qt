#include "chick.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "stats.h"
#include "spaceship.h"
#include <QMediaPlayer>
#include <QAudioOutput>


Chick::Chick() : QObject(), QGraphicsPixmapItem(QPixmap(":/img/Images/chicken.png").scaled(100,100))
{
    audioOutput = new QAudioOutput();
    soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl("qrc:/sounds/sounds/chicken-single-alarm-call-6056.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);

    int random_number = rand() % 700;
    setPos(random_number,0);
    goRight = rand() % 2;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Chick::move(){
    if(goRight)
    {
        setPos(x()+2,y()+5);
        if (pos().x() + 100 >= 800)
            goRight = false;
    }
    else
    {
        setPos(x()-2,y()+5);
        if (pos().x() <= 0)
            goRight = true;
    }

    // When chicken reaches the bottom, delete it and decrease health
    if (pos().y() + pixmap().height() > scene()->height()){
        Stats::decrease();
        scene()->removeItem(this);
        delete this;
        return;
    }


    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        SpaceShip* ship = dynamic_cast<SpaceShip*>(colliding_items[i]);
        if (ship != nullptr)
        {
            soundEffect->play();

            scene()->removeItem(this);

            Stats::decrease();

            delete this;
            return;
        }
    }
}

