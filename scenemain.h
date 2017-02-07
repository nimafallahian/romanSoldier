#ifndef SCENEMAIN_H
#define SCENEMAIN_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "obstacle.h"
#include "fighter.h"
#include "land.h"
#include "firstbutton.h"
//#include "mapdrawer.h"
class SceneMain : public QGraphicsScene
{
public:
    SceneMain(Fighter * player);
    FirstButton *button1;
    QVector <Obstacle*> map1Draw(Fighter * player, int difficulty , int gateWidth );
    int getHeight() const;
//    void setHeight(int value);
    int difficulty ;
    int gateWidth ;
    Land* lands;
//    mapDrawer* hisMajesty;
private:
    int width;
    int height;
    //    void mapdrawer(Fighter* player , int difficlty);
    QMediaPlayer * bgsound;
};

#endif // SCENEMAIN_H
