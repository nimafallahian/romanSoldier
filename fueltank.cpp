#include "fueltank.h"
#include "fighter.h"
FuelTank::FuelTank()
{
    height = 50;
    width = 50;
    Vspeed = 10;
    normalVspeed = 10;     //Vertical speed
    incVspeed = 20;
    decVspeed = 5;
    Hspeed = 0;     //Horizontal speed
    hDirection = 0;
    setRect(0,0,width,height);
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}

void FuelTank::moveV()
{
    Obstacle::moveV();
    QList <QGraphicsItem*> cldItems = collidingItems();
    for(int i = 0 ; i < cldItems.size() ; i++){
        if (typeid(*(cldItems[i])) == typeid(Fighter)){
//            Add fuel
//            qDebug() << "Refuel";
            return;
        }
    }
}

void FuelTank::speedUP()
{
    Vspeed = incVspeed ;
}

void FuelTank::speedDOWN()
{
    Vspeed = decVspeed;
}

void FuelTank::speedNORMAL()
{
    Vspeed = normalVspeed;
}

void FuelTank::STOP()
{
    Vspeed = 0;
    isMoving = 0;
}

void FuelTank::RESUME()
{
    Vspeed = normalVspeed;
    isMoving = 1;
}
