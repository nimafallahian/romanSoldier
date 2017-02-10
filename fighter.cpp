#include "fighter.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
Fighter::Fighter()
{
//    this->setRect(0,0,Fighterwidth,Fighterheight);
    setPixmap(QPixmap(":/images/player.png"));
    this->setPos(369,1900);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    fuelPack = new Fuel;
    fuelPack->setValue(100);
    fuelPack->setRange(0,100);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(decFuel()));
    timer->start(800);
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
        Bullet* bullet = new Bullet(this);
        bullet->setPos(x()+(Fighterwidth/2)-(Bulletwidth/2),y());
        scene()->addItem(bullet);

        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
    else if(k == Qt::Key_Up){
        qDebug() << "pressed";
        emit speedUp();
    }
    else if(k == Qt::Key_Down){
        qDebug() << "pressed";
        emit speedDown();
    }
    else if(k == Qt::Key_P){
        emit Stop();
    }
    else if(k == Qt::Key_R){
        emit Resume();
    }
//    else{
//        qDebug() << "other key";
    //    }
}

void Fighter::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        qDebug() << "released";
        emit speedNormal();
    }
    if(event->key() == Qt::Key_Down){
        qDebug() << "released";
        emit speedNormal();
    }
}

void Fighter::emitRes()
{
    qDebug() << "resumeeee";
    emit Resume();
}

bool Fighter::isEmpty()
{
    if(fuelPack->value() == 0)
        return 1;
    return 0;
}

void Fighter::emitStop()
{
    emit Stop();
}

void Fighter::decFuel()
{
    fuelPack->setValue(fuelPack->value() - fuelPack->decSpeed);
    if(isEmpty()){
        emit Stop();
    }
}

void Fighter::incFuel()
{
    int temp = fuelPack->value() + 20;
    qDebug() << temp;
    if(temp > 99){
        temp = 99;
    }
    fuelPack->setValue(temp);
}

void Fighter::stopFuel()
{
    fuelPack->decSpeed = 0;
}

void Fighter::resumeFuel()
{
    fuelPack->decSpeed = fuelPack->stnDecSpeed;
}
