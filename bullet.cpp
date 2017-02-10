#include "bullet.h"
#include <QDebug>
#include <typeinfo>
#include <QGraphicsItem>
#include "ship.h"
#include "helicopter.h"
#include "jet.h"
#include "land.h"
#include "gate.h"
#include "fighter.h"
#include "fueltank.h"
#include "obstacle.h"

extern Game * game;

Bullet::Bullet(Fighter * player)
{
    Vspeed = 10;
    normalSpeed = 10;
//    setRect(0,0,Bulletwidth,Bulletheight);
    setPixmap(QPixmap(":/images/bullet.png"));
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    connect(player,SIGNAL(Stop()),SLOT(STOP()));
    connect(player,SIGNAL(Resume()),this,SLOT(RESUME()));
}

void Bullet::move()
{
    setPos(x(),y()-Vspeed);
    QList <QGraphicsItem*> cldItems = collidingItems();
    for(int i = 0 ; i < cldItems.size() ; i++){
//        qDebug() << typeid(*(cldItems[i]));
        if(typeid(*(cldItems[i])) == typeid(Ship) ||typeid(*(cldItems[i])) == typeid(Helicopter)
                || typeid(*(cldItems[i])) == typeid(Jet) || typeid(*(cldItems[i])) == typeid(Gate)
                || typeid(*(cldItems[i])) == typeid(FuelTank)){
            if(typeid(*(cldItems[i])) == typeid(Ship) ||typeid(*(cldItems[i])) == typeid(Helicopter)
                    || typeid(*(cldItems[i])) == typeid(Jet)){
                game->score->increase();
            }
            Explosion * xplosion = new Explosion(x(), y() - 10);
            scene()->addItem(xplosion);
//            xplosion->set(x(), y() - 10);
            scene()->removeItem(cldItems[i]);
            scene()->removeItem(this);

            delete cldItems[i];
            delete this;
            return;
        }
        else if (typeid(*(cldItems[i])) == typeid(QGraphicsPixmapItem)){
            if(typeid(*(cldItems[i])) == typeid(Fighter)){
                continue;
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

//    if(y() + rect().height() < 1100){ // bullt.png's height is 100
    if(y() + 100 < 1100){
        qDebug() << "bullet deleted";
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::STOP()
{
    Vspeed = 0;
}
void Bullet::RESUME()
{
    Vspeed = normalSpeed;
    qDebug() << "back to normal";

}
