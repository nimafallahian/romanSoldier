#include "fueltank.h"
#include "fighter.h"
FuelTank::FuelTank()
{
    height = 50;
    width = 50;
    Vspeed = 10;     //Vertical speed
    Hspeed = 0;     //Horizontal speed
    hDirection = 0;
    isSmart = 0;
//    setRect(0,0,width,height);
    setPixmap(QPixmap(":/images/enemy.png"));
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
