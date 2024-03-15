#ifndef STATS_H
#define STATS_H
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
};

#endif // STATS_H
