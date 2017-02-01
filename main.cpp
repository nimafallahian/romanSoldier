#include <QApplication>
#include "viewmain.h"
#include "scenemain.h"
#include "fighter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SceneMain *scenemain = new SceneMain;
    Fighter *player = new Fighter;
    scenemain->addItem(player);
    player->setFocus();

    ViewMain *viewmain = new ViewMain(scenemain);
    player->setFocus();
    return a.exec();
}
