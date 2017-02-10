#include "jet.h"
#include "fighter.h"
Jet::Jet()
{
    height = 50;
    width = 60;
    Vspeed = 10;     //Vertical speed
    normalVspeed = 10;     //Vertical speed
    incVspeed = 20;
    decVspeed = 5;
    Hspeed = 15;     //Horizontal speed
    hDirection = rand()%2;
    startingY = (rand() % 300) + 1200;
    qDebug() << startingY;
//    setRect(0,0,width,height);
    setPixmap(QPixmap(":/images/jet.png"));
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
            emit Stop();
            return;
        }
    }
}


void Jet::speedUP()
{
    Vspeed = incVspeed ;
}

void Jet::speedDOWN()
{
    Vspeed = decVspeed;
}

void Jet::speedNORMAL()
{
    Vspeed = normalVspeed;
}
void Jet::STOP()
{
    Vspeed = 0;
    isMoving = 0;
}

void Jet::RESUME()
{
    Vspeed = normalVspeed;
    isMoving = 1;
}
