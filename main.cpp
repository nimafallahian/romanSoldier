#include <QApplication>
#include "viewmain.h"
#include "scenemain.h"
#include "fighter.h"
#include "land.h"
#include "mapdrawer.h"
#include "firstbutton.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fighter *player = new Fighter;
    SceneMain *scenemain = new SceneMain(player);
    scenemain->addItem(player);
    player->setFocus();
    FirstButton::onlyFighter = player;
//    scenemain->mapdrawer(player,0);
//    Land* land1 = new Land(0,20,600,scenemain);
//    Land* land2 = new Land(50,100,scenemain);
    QVector <Obstacle*> map1Obstacles = scenemain->map1Draw(player,0,300);
    mapDrawer *hisMajesty = new mapDrawer(scenemain, player);

    ViewMain *viewmain = new ViewMain(scenemain);
    player->setFocus();
    return a.exec();
}
