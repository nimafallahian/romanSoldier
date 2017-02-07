#include <QApplication>
#include "viewmain.h"
#include "scenemain.h"
#include "fighter.h"
#include "land.h"
#include "mapdrawer.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SceneMain *scenemain = new SceneMain;
    Fighter *player = new Fighter;
    scenemain->addItem(player);
    player->setFocus();
//    scenemain->mapdrawer(player,0);
//    Land* land1 = new Land(0,20,600,scenemain);
//    Land* land2 = new Land(50,100,scenemain);
    QVector <Obstacle*> map1Obstacles = scenemain->map1Draw(0,300);
    mapDrawer *hisMajesty = new mapDrawer(scenemain);

    ViewMain *viewmain = new ViewMain(scenemain);
    player->setFocus();
    return a.exec();
}
