#include <QApplication>
#include "SpaceShip.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include "spawner.h"
#include "stats.h"
#include <QMediaPlayer>
#include <QAudioOutput>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create scene
    QGraphicsScene * scene = new QGraphicsScene();

    // add chick to the scene
    QGraphicsPixmapItem * player = new SpaceShip();
    //player->setPos()

    //add player to scene
    scene-> addItem(player);

    //remove scroll bars
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    QPixmap bgImage(":/img/Images/space.jpg");
    scene->setBackgroundBrush(bgImage.scaled(scene->width(),scene->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //set pos of player
    player->setPos(view->width()/2,view->height() - player->pixmap().height());

    QGraphicsTextItem* scoreText = new QGraphicsTextItem();
    QGraphicsTextItem* healthText = new QGraphicsTextItem();

    scene->addItem(scoreText);
    scene->addItem(healthText);

    Stats::setHealthText(healthText);
    Stats::setScoreText(scoreText);

    // Instantiate Spawner
    Spawner spawner(scene);

    QAudioOutput* audioOutput = new QAudioOutput();
    QMediaPlayer* soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    soundEffect->setLoops(1000);
    soundEffect->play();

    return a.exec();
}
