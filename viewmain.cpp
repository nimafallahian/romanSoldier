#include "viewmain.h"
#include "scenemain.h"
ViewMain::ViewMain(SceneMain* scene)
{
    this->setFixedSize(800,600);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setScene(scene);
    this->show();
}
