#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "obstacle.h"
#include "fighter.h"
#include "land.h"
//#include "mapdrawer.h"
class SceneMain : public QGraphicsScene
{
public:
    SceneMain();
    QVector <Obstacle*> map1Draw( int difficulty , int gateWidth );
    int getHeight() const;
    void setHeight(int value);
    int difficulty ;
    int gateWidth ;
    Land* land1;
//    mapDrawer* hisMajesty;
private:
    Obstacle *pivot;
    int width;
    int height;
    //    void mapdrawer(Fighter* player , int difficlty);
    QMediaPlayer * bgsound;
};

#endif // SCENEMAIN_H
