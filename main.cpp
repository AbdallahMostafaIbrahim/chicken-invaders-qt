#include <QApplication>
#include "SpaceShip.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "spawner.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include"stats.h"
=======
#include "stats.h"
>>>>>>> 54cf620bbb013c156f016e4fe90f3770468cac98
=======
>>>>>>> parent of 54cf620 (stats)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create scene
    QGraphicsScene * scene = new QGraphicsScene();

    // add chick to the scene
    QGraphicsPixmapItem * player = new SpaceShip();
    Stats * stats = new Stats();

    //add player and stats to scene
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

    // Instantiate Spawner
    Spawner spawner(scene);

    return a.exec();
}
