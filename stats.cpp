#include "stats.h"
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QFont>
#include <QMediaPlayer>
#include <QAudioOutput>

int Stats::health = 3;
int Stats::score = 0;
QGraphicsTextItem* Stats::healthText = nullptr;
QGraphicsTextItem* Stats::scoreText = nullptr;


void Stats::setHealthText(QGraphicsTextItem* hText) {
    healthText = hText;
    healthText->setDefaultTextColor(Qt::red);
    healthText->setFont(QFont("serif", 22));
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10,20);
}

void Stats::setScoreText(QGraphicsTextItem* sText){
    scoreText = sText;
    scoreText->setDefaultTextColor(QColor(0x86BCFE));
    scoreText->setFont(QFont("serif", 22));
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(10,50);
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

        QAudioOutput* audioOutput = new QAudioOutput();
        QMediaPlayer* soundEffect = new QMediaPlayer();
        soundEffect->setSource(QUrl("qrc:/sounds/sounds/game-over-arcade-6435.mp3"));
        soundEffect->setAudioOutput(audioOutput);
        audioOutput->setVolume(50);
        soundEffect->play();

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle(QString("GET BETTER."));
        msg->setMinimumHeight(500);
        msg->setMinimumWidth(500);
        msg->setText(QString("GAME OVER. Your score was") + QString::number(score));
        msg->exec();
    }

}


