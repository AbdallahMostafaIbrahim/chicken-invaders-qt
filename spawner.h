#ifndef SPAWNER_H
#define SPAWNER_H
#include <QObject>
#include <QGraphicsScene>

class Spawner : public QObject
{
    Q_OBJECT
public:
    Spawner(QGraphicsScene*);
private:
    QGraphicsScene* scene;
public slots:
    void spawn();
};

#endif // SPAWNER_H
