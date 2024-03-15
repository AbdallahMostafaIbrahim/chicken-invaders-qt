#include "spawner.h"
#include "chick.h"
#include <QTimer>
#include <QGraphicsScene>

QTimer* Spawner::timer = new QTimer();

Spawner::Spawner(QGraphicsScene * scene) {
    this->scene = scene;

    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(1500);
}

void Spawner::stopSpawning() {
    timer->stop();
}

void Spawner::spawn(){
    Chick * enemy = new Chick();
    scene->addItem(enemy);
}
