#include "chick.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Chick::Chick() : QGraphicsPixmapItem(),QObject()
{
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
        if (pos().x() + 100 <= 0)
            goRight = true;
    }

        if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
