#ifndef SHIP_H
#define SHIP_H
#include "obstacle.h"
class Ship : public QObject ,public Obstacle
{
    Q_OBJECT
public:
    Ship(bool hdir);
public slots:
    void moveV();
//    void moveH();
};

#endif // SHIP_H
