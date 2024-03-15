#include "mainwindow.h"

#include <QApplication>
#include "chick.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create scene
    QGraphicsScene * scene = new QGraphicsScene();

    // add chick to the scene
    QGraphicsPixmapItem * player = new Chick ();
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

    //set pos of player
    player->setPos(view->width()/2,view->height() - player->pixmap().height());


    // spawn enemies
   /* QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
    */
    return a.exec();
}
