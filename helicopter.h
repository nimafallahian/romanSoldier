#ifndef HELICOPTER_H
#define HELICOPTER_H
#include "obstacle.h"
class Helicopter : public QObject ,public Obstacle
{
    Q_OBJECT
public:
    Helicopter(bool hdir);
public slots:
    void moveV();
//    void moveH();
};

#endif // HELICOPTER_H
