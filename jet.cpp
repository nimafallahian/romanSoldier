#include "jet.h"
#include "fighter.h"
Jet::Jet()
{
    height = 50;
    width = 60;
    Vspeed = 10;     //Vertical speed
    Hspeed = 15;     //Horizontal speed
//    hDirection = -1;
    hDirection = rand()%2;
    isSmart = 1;
    startingY = (rand() % 300) + 1200;
    qDebug() << startingY;
    setRect(0,0,width,height);
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}

void Jet::moveV()
{
    Obstacle::moveV();
    if(y() > startingY){
        Obstacle::moveH();
    }
    QList <QGraphicsItem*> cldItems = collidingItems();
    for(int i = 0 ; i < cldItems.size() ; i++){
        if (typeid(*(cldItems[i])) == typeid(Fighter)){
            // Defeat
            qDebug() << "Defeat";
            return;
        }
    }
}
