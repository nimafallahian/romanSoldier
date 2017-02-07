#include "gate.h"
#include "fighter.h"
Gate::Gate(int iwidth)
{
    qDebug() << "make gate";
    height = 50;
    width = iwidth;
    Vspeed = 10;     //Vertical speed
    normalVspeed = 10;     //Vertical speed
    incVspeed = 20;
    decVspeed = 5;
    Hspeed = 0;     //Horizontal speed
    hDirection = 1;
//    setRect(0,0,width,height);
    setPixmap(QPixmap(":/images/enemy.png"));
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

void Gate::speedUP()
{
    Vspeed = incVspeed ;
}

void Gate::speedDOWN()
{
    Vspeed = decVspeed;
}

void Gate::speedNORMAL()
{
    Vspeed = normalVspeed;
}
void Gate::STOP()
{
    Vspeed = 0;
    isMoving = 0;
}

void Gate::RESUME()
{
    Vspeed = normalVspeed;
    isMoving = 1;
}
