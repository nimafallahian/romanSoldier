#include "mapdrawer.h"
#include "QDebug"
mapDrawer::mapDrawer(SceneMain* mysceneInp,Fighter* player)
{
    this->player = player;
    myscene = mysceneInp;
    connect(mysceneInp->lands,SIGNAL(end()),this,SLOT(map1Draw()));
    qDebug() << "connected";
}

void mapDrawer::map1Draw()
{
    myscene->map1Draw(player,myscene->difficulty,myscene->gateWidth);
    connect(myscene->lands,SIGNAL(end()),this,SLOT(map1Draw()));
    qDebug() << "slot called";
}
