#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "obstacle.h"
#include "fighter.h"
#include "land.h"
//#include "mapdrawer.h"
class SceneMain : public QGraphicsScene
{
public:
    SceneMain();
    QVector <Obstacle*> map1Draw(Fighter* player, int difficulty , int gateWidth );
    int getHeight() const;
    int difficulty ;
    int gateWidth ;
    Land* lands;
//    mapDrawer* hisMajesty;
private:
    int width;
    int height;
    //    void mapdrawer(Fighter* player , int difficlty);
};

#endif // SCENEMAIN_H
