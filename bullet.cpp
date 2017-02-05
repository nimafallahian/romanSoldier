#include "bullet.h"
#include <QDebug>
#include <QTimer>
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
Bullet::Bullet()
{
    setRect(0,0,Bulletwidth,Bulletheight);
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    setPos(x(),y()-10);
    QList <QGraphicsItem*> cldItems = collidingItems();
    for(int i = 0 ; i < cldItems.size() ; i++){
//        qDebug() << typeid(*(cldItems[i]));
        if(typeid(*(cldItems[i])) == typeid(Ship) ||typeid(*(cldItems[i])) == typeid(Helicopter)
                || typeid(*(cldItems[i])) == typeid(Jet) || typeid(*(cldItems[i])) == typeid(Gate)
                || typeid(*(cldItems[i])) == typeid(FuelTank)){
            scene()->removeItem(cldItems[i]);
            scene()->removeItem(this);
            delete cldItems[i];
            delete this;
            return;
        }
        else if (typeid(*(cldItems[i])) == typeid(QGraphicsRectItem)){
            if(typeid(*(cldItems[i])) == typeid(Fighter)){
                continue;
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if(y() + rect().height() < 1100){
        qDebug() << "bullet deleted";
        scene()->removeItem(this);
        delete this;
    }
}
