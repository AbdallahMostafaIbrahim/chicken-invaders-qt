#include "spawner.h"
#include <QTimer>
#include "chick.h"
#include <QGraphicsScene>

Spawner::Spawner(QGraphicsScene * scene) {
    this->scene = scene;
    // spawn enemies
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(2000);
}

void Spawner::spawn(){
    // create an enemy
    Chick * enemy = new Chick();
    scene->addItem(enemy);
}
