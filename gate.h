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
};

#endif // GATE_H
