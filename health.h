#ifndef HEALTH_H
#define HEALTH_H

class Health : public QGraphicsTextItem, QObject
{
private:
    static int health;
public:
    Health();
    void increase();
    void decrease();
};

#endif // HEALTH_H
