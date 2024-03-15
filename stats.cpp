#include "stats.h"
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QFont>

int Stats::health = 3;
int Stats::score = 0;
QGraphicsTextItem* Stats::healthText = nullptr;
QGraphicsTextItem* Stats::scoreText = nullptr;

void Stats::setHealthText(QGraphicsTextItem* hText) {
    healthText = hText;
    healthText->setDefaultTextColor(Qt::red);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10,20);
}

void Stats::setScoreText(QGraphicsTextItem* sText){
    scoreText = sText;
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(10,40);
}

void Stats::increase() {
    score += 100;
    scoreText->setPlainText("Score: " + QString::number(score));
}

void Stats::decrease() {
    if(health > 0){
        health--;
        score -= 100;
    }
    healthText->setPlainText("Health: " + QString::number(health));
    scoreText->setPlainText("Score: " + QString::number(score));
    QGraphicsScene* s = healthText->scene();

    if(health == 0) {
        s->clear();
        QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setFont(QFont("serif", 48));
        gameOverText->setPlainText("GAME OVER!");
        gameOverText->setPos(s->width() / 2 - 180, s->height() / 2 - 48);

        s->addItem(gameOverText);

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle(QString("GET BETTER."));
        msg->setMinimumHeight(500);
        msg->setMinimumWidth(500);
        msg->setText(QString("GAME OVER. Your score was") + QString::number(score));
        msg->exec();
    }

}


>>>>>>> 54cf620bbb013c156f016e4fe90f3770468cac98
