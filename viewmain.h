#ifndef VIEWMAIN_H
#define VIEWMAIN_H
#include <QGraphicsView>
#include "scenemain.h"
class ViewMain : public QGraphicsView
{
public:
    ViewMain(SceneMain* scene);
};

#endif // VIEWMAIN_H
