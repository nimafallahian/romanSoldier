#include "land.h"
#include "fighter.h"
#include <QDebug>
#include <QTimer>
#include <typeinfo>
Land::Land(bool RL, int width,int height , int gateWidth,QGraphicsScene* scene)
{
    nextOne = 0;
    Vspeed = 10;
    normalVspeed = 10;     //Vertical speed
    incVspeed = 20;
    decVspeed = 5;
    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0,0,width,height);
    if(RL){
        rect->setPos(scene->width()- width , 0);
    }
    scene->addItem(rect);
    rects.push_back(rect);

    if(RL){
        int widthStep = ((400 - gateWidth/2) - width)/5;
        for(int i = 0 ; i < 5 ; i++){
            QGraphicsRectItem* rect = new QGraphicsRectItem();
            rect->setRect(0,0,width + (widthStep*(5-i)),10);
            rect->setPos(700-(widthStep*(5-i)),0 + (10*i));
            scene->addItem(rect);
            rects.push_back(rect);
        }
        for(int i = 0 ; i < 5 ; i++){
            QGraphicsRectItem* rect = new QGraphicsRectItem();
            rect->setRect(0,0,width + (widthStep*(i+1)),10);
            rect->setPos(700-(widthStep*(i+1)),950 + (10*i));
            scene->addItem(rect);
            rects.push_back(rect);
        }
    }
    else{
        int widthStep = ((400 - gateWidth/2) - width)/5;
        for(int i = 0 ; i < 5 ; i++){
            QGraphicsRectItem* rect = new QGraphicsRectItem();
            rect->setRect(0,0,width + (widthStep*(5-i)),10);
            rect->setPos(0,0 + (10*i));
            scene->addItem(rect);
            rects.push_back(rect);
        }
        for(int i = 0 ; i < 5 ; i++){
            QGraphicsRectItem* rect = new QGraphicsRectItem();
            rect->setRect(0,0,width + (widthStep*(i+1)),10);
            rect->setPos(0,950 + (10*i));
            scene->addItem(rect);
            rects.push_back(rect);
        }
    }
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}


Land::Land(int width, int height,QGraphicsScene* scene)
{
    qDebug() << "Mland";
    int xcenter = scene->width()/2;
    int ycenter = scene->height()/2;
    int tmpwidth = width;
    const int widthStep = 10;
    int totalStep = width / widthStep;
    int tmpheight = 10;
    const int heightStep = height / (totalStep);
    for(int i = 0 ; i < totalStep ; i++){
        qDebug() << tmpwidth << tmpheight;
        QGraphicsRectItem* rect = new QGraphicsRectItem();
        rect->setRect(0,0,tmpwidth,tmpheight);
        rect->setPos(xcenter - (tmpwidth/2) , ycenter - (tmpheight/2));
        scene->addItem(rect);
        tmpheight += heightStep;
        tmpwidth -= widthStep;
        rects.push_back(rect);
    }
    QTimer* timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveV()));
    timer->start(50);
    Vtimer = timer;
}

bool Land::InOut()
{
    return (rects[1]->y() < rects[1]->scene()->height() + 500);
}

bool Land::Inview()
{
    if(rects[1]->y() > 1000){
        return 1;
    }
}

void Land::moveV()
{
    if (!InOut()){
        for(int i = 0 ; i < rects.size() ; i++){
            delete rects[i];
        }
        Vtimer->stop();
        delete Vtimer;
        return;
    }
    if (Inview()){
        if(!nextOne){
            qDebug() << "inview signal emitted";
            emit end();
            nextOne = 1;
        }
    }
    for(int i = 0 ; i < rects.size() ; i++){
        rects[i]->setPos(rects[i]->x(),rects[i]->y() + Vspeed);
    }
    for(int i = 0; i < rects.size() ; i++){
        QList <QGraphicsItem*> cldItems = rects[i]->collidingItems();
        for(int i = 0 ; i < cldItems.size() ; i++){
            if (typeid(*(cldItems[i])) == typeid(Fighter)){
                // Defeat
                qDebug() << "Defeat";
                return;
            }
        }
    }
}

void Land::speedUP()
{
    Vspeed = incVspeed;
}

void Land::speedDOWN()
{
    Vspeed = decVspeed;
}

void Land::speedNORMAL()
{
    Vspeed = normalVspeed;
}
void Land::STOP()
{
    Vspeed = 0;
}

void Land::RESUME()
{
    Vspeed = normalVspeed;
}
