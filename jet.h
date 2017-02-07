#ifndef JET_H
#define JET_H
#include "obstacle.h"
class Jet :public QObject , public Obstacle
{
    Q_OBJECT
public:
    Jet();
    int startingY;
public slots:
    void moveV();
//    void moveH();
};

#endif // JET_H
