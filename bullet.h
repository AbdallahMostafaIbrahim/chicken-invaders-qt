#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Bullet : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    Bullet();
private:
    QMediaPlayer* soundEffect;
    QAudioOutput* audioOutput;
public slots:
    void move();
};

#endif // BULLET_H
