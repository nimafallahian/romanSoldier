#include "obstacle.h"
#include "land.h"
Obstacle::Obstacle()
{
//    QTimer* timer = new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //    timer->start(50);
}
bool Obstacle::getHDirection() const
{
    return hDirection;
}


void Obstacle::moveV()
{
//    int currentx = x();
    int currenty = y();
//    int nextx;
    int nexty;
//    nextx = currentx;
    nexty = currenty;
//    nextx = currentx + (Hspeed * ((2*hDirection)-1));
    nexty = currenty + Vspeed;
    this->setPos(x(),nexty);
    if(y() > scene()->height() + 500){
        scene()->removeItem(this);
        delete this;
    }
}

void Obstacle::moveH()
{
        int nextx;
        nextx = x() + (Hspeed * ((2*hDirection)-1));
        this->setPos(nextx,y());
}
//Obstacle::~Obstacle()
//{
//    Vtimer->stop();
//    delete Vtimer;
//    delete this;
//}
