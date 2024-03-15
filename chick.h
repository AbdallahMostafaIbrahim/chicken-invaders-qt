#ifndef CHICK_H
#define CHICK_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Chick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool goRight;

public:
    Chick();

public slots:
    void move();
};

#endif // CHICK_H
