#include "viewmain.h"
#include "scenemain.h"
ViewMain::ViewMain(SceneMain* scene)
{
    width = 800;
    height = 900;
    this->setFixedSize(width,height);
//    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setScene(scene);
    this->centerOn(400,1550);
    this->show();
}
