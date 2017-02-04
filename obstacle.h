#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include "land.h"
class Obstacle :/*public QObject ,*/ public QGraphicsRectItem
{
//     Q_OBJECT
public:
    Obstacle();
//    ~Obstacle();
protected:
    int height;
    int width;
    int Vspeed;     //Vertical speed
    int Hspeed;     //Horizontal speed
    bool hDirection;
    bool isSmart;
    QTimer *Vtimer;
public :
    void moveV();
    void moveH();
    bool getHDirection() const;
};

#endif // OBSTACLE_H
