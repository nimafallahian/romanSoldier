#include "gate.h"
#include "fighter.h"
Gate::Gate(int iwidth)
{
    qDebug() << "make gate";
    height = 50;
    width = iwidth;
    Vspeed = 10;     //Vertical speed
    Hspeed = 0;     //Horizontal speed
    hDirection = 1;
    isSmart = 1;
    setRect(0,0,width,height);
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}

void Gate::moveV()
{
    Obstacle::moveV();
    QList <QGraphicsItem*> cldItems = collidingItems();
    for(int i = 0 ; i < cldItems.size() ; i++){
        if (typeid(*(cldItems[i])) == typeid(Fighter)){
            // Defeat
            qDebug() << "Defeat";
            return;
        }
    }
}
