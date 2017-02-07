#include "explosion.h"

Explosion::Explosion(int width, int height)
{
    explosionSound = new QMediaPlayer();
    explosionSound->setMedia(QUrl("qrc:/sounds/explosion.mp3"));
    explosionSound->play();
    setPixmap(QPixmap(":/images/explosion.png"));
    this->setPos(width - 50, height - 50);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(destruct()));
    timer->start(200);
}

void Explosion::destruct()
{
    timer->stop();
    scene()->removeItem(this);
}
