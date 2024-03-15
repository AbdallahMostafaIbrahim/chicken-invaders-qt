#include "chick.h"

Chick::Chick() : QGraphicsPixmapItem(),QObject() //: QGraphicsPixmapItem(QPixmap(":/img/Images/chicken.png").scaled(100,100))
 {
    setPixmap(QPixmap(":/img/Images/chicken.png").scaled(100,100));

}
