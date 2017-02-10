#include "firstbutton.h"
#include "fighter.h"

//Fighter * FirstButton::onlyFighter = 0;

FirstButton::FirstButton(Fighter * onlyFighter)
{
    qDebug() << "make button";
    setPixmap(QPixmap(":/images/continue.png"));
//    setRect(200, 100, 369, 1500);
    this->setPos(350,1500);
    this->onlyFighter = onlyFighter;
    this->setZValue(1);
}
/*
void FirstButton::STOP(int val){
    setPixmap(QPixmap(":/images/stop.png"));

    this->show();
    // boom the game
} */

void FirstButton::STOP()
{
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->show();
}

void FirstButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit Resume();
//    emit SIGNAL(this->onlyFighter->Resume());
    onlyFighter->emitRes();
    onlyFighter->setFocus();
//    qDebug() << "zhooon oooom areee";
    this->hide();

}
