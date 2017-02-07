#include "fighter.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
Fighter::Fighter()
{
    this->setRect(0,0,Fighterwidth,Fighterheight);
    this->setPos(369,1900);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}
void Fighter::keyPressEvent(QKeyEvent* event)
{
    int k = event->key();
//    qDebug() << "key";
    if (k == Qt::Key_Left){
        this->setPos(this->x()-20,this->y());
    }
    else if(k == Qt::Key_Right){
        this->setPos(this->x()+20,this->y());
    }
    else if(k == Qt::Key_Space){
//        qDebug() << "bullet created";
        Bullet* bullet = new Bullet(this);
        bullet->setPos(x()+(Fighterwidth/2)-(Bulletwidth/2),y());
        scene()->addItem(bullet);
    }
    else if(k == Qt::Key_Up){
        qDebug() << "pressed";
        emit speedUp();
    }
    else if(k == Qt::Key_Down){
        qDebug() << "pressed";
        emit speedDown();
    }
    else if(k == Qt::Key_P){
        emit Stop();
    }
    else if(k == Qt::Key_R){
        emit Resume();
    }
//    else{
//        qDebug() << "other key";
    //    }
}

void Fighter::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        qDebug() << "released";
        emit speedNormal();
    }
    if(event->key() == Qt::Key_Down){
        qDebug() << "released";
        emit speedNormal();
    }

}
