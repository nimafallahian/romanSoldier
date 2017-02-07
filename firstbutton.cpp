#include "firstbutton.h"
#include "fighter.h"

Fighter * FirstButton::onlyFighter = 0;

FirstButton::FirstButton()
{
    qDebug() << "make button";
    setPixmap(QPixmap(":/images/button.png"));
//    setRect(200, 100, 369, 1500);
    this->setPos(300,1500);
}

void FirstButton::STOP()
{
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->show();
}

void FirstButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit Resume();
    onlyFighter->setFocus();
    qDebug() << "zhooon oooom areee";
    this->hide();

}
