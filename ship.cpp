#include "ship.h"
#include "fighter.h"
Ship::Ship(bool hdir)
{
    height = 50;
    width = 160;
    Vspeed = 10;
    normalVspeed = 10;     //Vertical speed
    incVspeed = 20;
    decVspeed = 5;
    Hspeed = 5;     //Horizontal speed
    hDirection = hdir;
//    setRect(0,0,width,height);
    setPixmap(QPixmap(":/images/ship.png"));
    if(hDirection == 1)
        setPixmap(QPixmap(":/images/ship1.png"));
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
            emit Stop();
            return;
        }
        else if(typeid(*(cldItems[i])) == typeid(QGraphicsPixmapItem)){
            if(cldItems[i]->x() > x()){
                setPixmap(QPixmap(":/images/ship.png"));
                hDirection = 0;
            }
            else if(cldItems[i]->x() < x()){
                setPixmap(QPixmap(":/images/ship1.png"));
                hDirection = 1;
            }
//            hDirection = (hDirection*(-1)) + 1;
        }

    }
}

void Ship::speedUP()
{
    Vspeed = incVspeed;
}

void Ship::speedDOWN()
{
    Vspeed = decVspeed;
}

void Ship::speedNORMAL()
{
    Vspeed = normalVspeed;
}
void Ship::STOP()
{
    Vspeed = 0;
    isMoving = 0;
}
void Ship::RESUME()
{
    Vspeed = normalVspeed;
    isMoving = 1;
}
