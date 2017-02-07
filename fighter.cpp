#include "fighter.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>

Fighter::Fighter()
{
//    this->setRect(0,0,Fighterwidth,Fighterheight);
    setPixmap(QPixmap(":/images/player.png"));
    this->setPos(369,1900);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
}
void Fighter::keyPressEvent(QKeyEvent* event)
{
    int k = event->key();
//    qDebug() << "key";
    if (k == Qt::Key_Left){
        this->setPos(this->x()-20,this->y());
    }
    else if(k == Qt::Key_Right){
        this->setPos(this->x()+20,this->y());
    }
    else if(k == Qt::Key_Space){
//        qDebug() << "bullet created";
        Bullet* bullet = new Bullet();
        bullet->setPos(x()+(Fighterwidth/2)-(Bulletwidth/2),y());
        scene()->addItem(bullet);

        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
//    else{
//        qDebug() << "other key";
//    }
}
