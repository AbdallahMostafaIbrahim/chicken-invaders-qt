#ifndef CHICK_H
#define CHICK_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Chick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Chick();
   // void move();
   // void gameover();
    //void keyPressEvent(QKeyEvent * event);

public slots:
    //void spawn();

};

#endif // CHICK_H
