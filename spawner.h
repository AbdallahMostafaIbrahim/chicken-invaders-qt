#ifndef SPAWNER_H
#define SPAWNER_H
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Spawner : public QObject
{
    Q_OBJECT
public:
    Spawner(QGraphicsScene*);
    static void stopSpawning();
private:
    static QTimer* timer;
    QGraphicsScene* scene;
public slots:
    void spawn();
};

#endif // SPAWNER_H
