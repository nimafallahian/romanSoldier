#include "scenemain.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include "gate.h"
SceneMain::SceneMain()
{
    width = 800;
    height = 2000;
    this->setSceneRect(0,0,width,height);
}
QVector <Obstacle*> SceneMain::map1Draw(Fighter *player, int difficulty , int gateWidth)
{
    QVector <Obstacle*> obstacles;
    Land *Lland1 = new Land(0,100,1000,gateWidth,this);
    Land *Lland2 = new Land(1,100,1000,gateWidth,this);
    Gate *gate = new Gate(gateWidth);
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
        //make heli
    }
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][1] ; j++){
        //make ship
        qDebug() << "draw ship";
        Ship *ship = new Ship (1);
        addItem(ship);
        obstacles.push_back(ship);
    }
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][2] ; j++){
        //make jet
        qDebug() << "draw jet";
        Jet *jet = new Jet;
        addItem(jet);
        obstacles.push_back(jet);
    }
    for(int j = 0 ; j < enemyDiffultyTable[difficulty][3] ; j++){
        //make fuel
        qDebug() << "draw fuel";
        FuelTank *fuel = new FuelTank;
        addItem(fuel);
        obstacles.push_back(fuel);
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
