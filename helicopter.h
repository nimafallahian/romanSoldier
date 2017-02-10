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
    void speedUP();
    void speedDOWN();
    void speedNORMAL();
    void STOP();
    void RESUME();
//    void moveH();
signals:
    void Stop();
};

#endif // HELICOPTER_H
