#include "mapdrawer.h"
#include "QDebug"
mapDrawer::mapDrawer(SceneMain* mysceneInp)
{
    myscene = mysceneInp;
    connect(mysceneInp->land1,SIGNAL(end()),this,SLOT(map1Draw()));
    qDebug() << "connected";
}

void mapDrawer::map1Draw()
{
    myscene->map1Draw(myscene->difficulty,myscene->gateWidth);
    connect(myscene->land1,SIGNAL(end()),this,SLOT(map1Draw()));
    qDebug() << "slot called";
}
