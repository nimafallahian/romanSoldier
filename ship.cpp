#include "ship.h"
#include "fighter.h"
Ship::Ship(bool hdir)
{
    height = 50;
    width = 160;
    Vspeed = 10;     //Vertical speed
    Hspeed = 5;     //Horizontal speed
    hDirection = hdir;
    isSmart = 0;
//    setRect(0,0,width,height);
    setPixmap(QPixmap(":/images/ship.png"));
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}

void Ship::moveV()
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
        else if(typeid(*(cldItems[i])) == typeid(QGraphicsPixmapItem)){
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
