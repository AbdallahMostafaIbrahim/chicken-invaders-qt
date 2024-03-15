#include "spawner.h"
#include <QTimer>
#include "chick.h"
#include <QGraphicsScene>


QTimer* Spawner::timer = new QTimer();

Spawner::Spawner(QGraphicsScene * scene) {
    this->scene = scene;
    // spawn enemies

    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(2000);
}

void Spawner::spawn(){
    // create an enemy
    Chick * enemy = new Chick();
    scene->addItem(enemy);
}
