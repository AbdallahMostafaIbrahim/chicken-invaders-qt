#ifndef STATS_H
#define STATS_H
<<<<<<< HEAD
#include<QGraphicsItem>
#include <QObject>

class Stats : QGraphicsTextItem
{
private:
static int health ;
static int score ;

public:
    Stats();
    void increase();
    void decrease();
=======
#include <QGraphicsTextItem>

class Stats
{
private:
    static int health;
    static int score;
    static QGraphicsTextItem* healthText;
    static QGraphicsTextItem* scoreText;
public:
    Stats();
    static void setHealthText(QGraphicsTextItem* healthText);
    static void setScoreText(QGraphicsTextItem* scoreText);
    static void increase();
    static void decrease();
>>>>>>> 54cf620bbb013c156f016e4fe90f3770468cac98
};

#endif // STATS_H
