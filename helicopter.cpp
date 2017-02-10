#include "helicopter.h"
#include "land.h"
#include "fighter.h"
Helicopter::Helicopter(bool hdir)
{
    height = 50;
    width = 120;
    Vspeed = 10;     //Vertical speed
    normalVspeed = 10;     //Vertical speed
    incVspeed = 20;
    decVspeed = 5;
    Hspeed = 10;     //Horizontal speed
    hDirection = hdir;
//    setRect(0,0,width,height);
    setPixmap(QPixmap(":/images/heli.png"));
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}

void Helicopter::moveV()
{
    Obstacle::moveV();
    Obstacle::moveH();
    QList <QGraphicsItem*> cldItems = collidingItems();
    for(int i = 0 ; i < cldItems.size() ; i++){
        if (typeid(*(cldItems[i])) == typeid(Fighter)){
            // Defeat
            qDebug() << "Defeat";
            emit Stop();
            return;
        }
        else if(typeid(*(cldItems[i])) == typeid(QGraphicsPixmapItem) ){
            if(cldItems[i]->x() > x()){
                hDirection = 0;
            }
            else if(cldItems[i]->x() < x()){
                hDirection = 1;
            }
//            hDirection = (hDirection*(-1)) + 1;
        }

    }
}


void Helicopter::speedUP()
{
    Vspeed = incVspeed ;
}

void Helicopter::speedDOWN()
{
    Vspeed = decVspeed;
}

void Helicopter::speedNORMAL()
{
    Vspeed = normalVspeed;
}
void Helicopter::STOP()
{
    Vspeed = 0;
    isMoving = 0;
}

void Helicopter::RESUME()
{
    Vspeed = normalVspeed;
    isMoving = 1;
}

