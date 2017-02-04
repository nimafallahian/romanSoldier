#include "helicopter.h"
#include "land.h"
#include "fighter.h"
Helicopter::Helicopter(bool hdir)
{
    height = 50;
    width = 120;
    Vspeed = 10;     //Vertical speed
    Hspeed = 10;     //Horizontal speed
    hDirection = hdir;
    isSmart = 1;
    setRect(0,0,width,height);
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
            return;
        }
        else if(typeid(*(cldItems[i])) == typeid(QGraphicsRectItem) ){
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
