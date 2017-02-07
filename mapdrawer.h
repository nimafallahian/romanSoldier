#ifndef MAPDRAWER_H
#define MAPDRAWER_H
#include <QObject>
//#include "obstacle.h"
#include "scenemain.h"
class mapDrawer : public QObject
{
    Q_OBJECT
private:
    SceneMain* myscene;
public:
    mapDrawer(SceneMain* myscene , Fighter* player);
    Fighter *player;
//    QVector <Obstacle*> (map1Draw) (int difficulty , int gateWidth , mapDrawer* hisMajesty);
public slots:
    void map1Draw();
};

#endif // MAPDRAWER_H
