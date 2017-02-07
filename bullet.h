#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include "fighter.h"
#define Bulletwidth 5
#define Bulletheight 8
class Bullet :public QObject , public QGraphicsRectItem
{
    Q_OBJECT
private:
    int Vspeed;
    int normalSpeed;
public:
    Bullet(Fighter *);
public slots:
    void move();
    void STOP();
    void RESUME();
};

#endif // BULLET_H
