#ifndef FUELTANK_H
#define FUELTANK_H
#include "obstacle.h"
class FuelTank : public QObject ,public Obstacle
{
    Q_OBJECT
public:
    FuelTank();
public slots:
    void moveV();
//    void moveH();
};

#endif // FUELTANK_H
