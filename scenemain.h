#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "fighter.h"
#include "obstacle.h"
#include "helicopter.h"
#include "jet.h"
#include "ship.h"
#include "fueltank.h"
class SceneMain : public QGraphicsScene
{
public:
    SceneMain();
    QVector <Obstacle*> map1Draw(Fighter* player , int difficulty , int gateWidth);
private:
    int width;
    int height;
//    void mapdrawer(Fighter* player , int difficlty);
};

#endif // SCENEMAIN_H
