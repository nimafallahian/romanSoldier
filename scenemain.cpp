#include "scenemain.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include "gate.h"
#include "fighter.h"
#include "helicopter.h"
#include "jet.h"
#include "ship.h"
#include "fueltank.h"
#include "land.h"
#include "mapdrawer.h"
SceneMain::SceneMain()
{
    width = 800;
    height = 2000;
    this->setSceneRect(0,0,width,height);
}
QVector <Obstacle*> SceneMain::map1Draw(Fighter* player, int difficulty , int gateWidth )
{
    this->difficulty = difficulty;
    this->gateWidth = gateWidth;
    QVector <Obstacle*> obstacles;
    Land *Lland1 = new Land(0,100,1000,gateWidth,this);
    this->lands = Lland1;
//    qDebug() << "connected";
//    connect(Lland1,SIGNAL(end()),hisMajesty,SLOT(map1Draw()));
    Land *Lland2 = new Land(1,100,1000,gateWidth,this);
    connect(player,SIGNAL(speedUp()),Lland1,SLOT(speedUP()));
    connect(player,SIGNAL(speedDown()),Lland1,SLOT(speedDOWN()));
    connect(player,SIGNAL(speedNormal()),Lland1,SLOT(speedNORMAL()));
    connect(player,SIGNAL(Stop()),Lland1,SLOT(STOP()));
    connect(player,SIGNAL(Resume()),Lland1,SLOT(RESUME()));

    connect(player,SIGNAL(speedUp()),Lland2,SLOT(speedUP()));
    connect(player,SIGNAL(speedDown()),Lland2,SLOT(speedDOWN()));
    connect(player,SIGNAL(speedNormal()),Lland2,SLOT(speedNORMAL()));
    connect(player,SIGNAL(Stop()),Lland2,SLOT(STOP()));
    connect(player,SIGNAL(Resume()),Lland2,SLOT(RESUME()));
    Gate *gate = new Gate(gateWidth);
    connect(player,SIGNAL(speedUp()),gate,SLOT(speedUP()));
    connect(player,SIGNAL(speedDown()),gate,SLOT(speedDOWN()));
    connect(player,SIGNAL(speedNormal()),gate,SLOT(speedNORMAL()));
    connect(player,SIGNAL(Stop()),gate,SLOT(STOP()));
    connect(player,SIGNAL(Resume()),gate,SLOT(RESUME()));
    addItem(gate);
    gate->setPos((this->width/2) - (gateWidth/2) , 0);
    qDebug() << (this->width/2) - (gateWidth/2) ;
    //array [lvl][objectNum]
    //heli - ship - jet - bridge - empty - fuel
    int enemyDiffultyTable[6][5] = {3,3,2,4,6
/                                   2,2,0,0,4
/                                   2,2,0,1,3
/                                   2,2,1,1,2
/                                   2,2,2,1,1
/                                   3,2,3,1,1};
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][0] ; j++){
        qDebug() << "draw heli";
        Helicopter *heli = new Helicopter (1);
        addItem(heli);
        obstacles.push_back(heli);
        connect(player,SIGNAL(speedUp()),heli,SLOT(speedUP()));
        connect(player,SIGNAL(speedDown()),heli,SLOT(speedDOWN()));
        connect(player,SIGNAL(speedNormal()),heli,SLOT(speedNORMAL()));
        connect(player,SIGNAL(Stop()),heli,SLOT(STOP()));
        connect(player,SIGNAL(Resume()),heli,SLOT(RESUME()));
        //make heli
    }
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][1] ; j++){
        //make ship
        qDebug() << "draw ship";
        Ship *ship = new Ship (1);
        addItem(ship);
        obstacles.push_back(ship);
        connect(player,SIGNAL(speedUp()),ship,SLOT(speedUP()));
        connect(player,SIGNAL(speedDown()),ship,SLOT(speedDOWN()));
        connect(player,SIGNAL(speedNormal()),ship,SLOT(speedNORMAL()));
        connect(player,SIGNAL(Stop()),ship,SLOT(STOP()));
        connect(player,SIGNAL(Resume()),ship,SLOT(RESUME()));
    }
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][2] ; j++){
        //make jet
        qDebug() << "draw jet";
        Jet *jet = new Jet;
        addItem(jet);
        obstacles.push_back(jet);
        connect(player,SIGNAL(speedUp()),jet,SLOT(speedUP()));
        connect(player,SIGNAL(speedDown()),jet,SLOT(speedDOWN()));
        connect(player,SIGNAL(speedNormal()),jet,SLOT(speedNORMAL()));
        connect(player,SIGNAL(Stop()),jet,SLOT(STOP()));
        connect(player,SIGNAL(Resume()),jet,SLOT(RESUME()));
    }
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][3] ; j++){
        //make fuel
        qDebug() << "draw fuel";
        FuelTank *fuel = new FuelTank;
        addItem(fuel);
        obstacles.push_back(fuel);
        connect(player,SIGNAL(speedUp()),fuel,SLOT(speedUP()));
        connect(player,SIGNAL(speedDown()),fuel,SLOT(speedDOWN()));
        connect(player,SIGNAL(speedNormal()),fuel,SLOT(speedNORMAL()));
        connect(player,SIGNAL(Stop()),fuel,SLOT(STOP()));
        connect(player,SIGNAL(Resume()),fuel,SLOT(RESUME()));
    }
    int objects = obstacles.size();
    bool used[18] = {0};
    int randomnum;
    srand(time(NULL));
    for (int i = 0 ; i < objects ; i++)
    {
        randomnum = rand() % 18;
        qDebug() << randomnum;
        if(used[randomnum]){
            while(used[randomnum]){
                randomnum++;
                randomnum %= 18;
            }
        }
        int randomx ;
        if(typeid(*obstacles[i]) == typeid(Jet)){

            qDebug() <<"setpos jet";
            randomx = (obstacles[i]->getHDirection())*(-1000) + 900;
        }
        else{
            randomx = (rand() % 440) + 100;
        }
        qDebug() << randomnum << randomx;
        obstacles[i]->setPos(randomx,(randomnum*50)+50);
        used[randomnum] = 1;
    }

    obstacles.push_back(gate);
    return obstacles;
}
