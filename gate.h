#ifndef GATE_H
#define GATE_H

#include "obstacle.h"
class Gate : public QObject ,public Obstacle
{
    Q_OBJECT
public:
    Gate(int gateWidth);
public slots:
    void moveV();
    void speedUP();
    void speedDOWN();
    void speedNORMAL();
    void STOP();
    void RESUME();
};

#endif // GATE_H
