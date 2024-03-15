#ifndef CHICK_H
#define CHICK_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Chick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool goRight;
    QMediaPlayer* soundEffect;
    QAudioOutput* audioOutput;
public:
    Chick();

public slots:
    void move();
};

#endif // CHICK_H
