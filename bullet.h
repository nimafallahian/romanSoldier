#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "fighter.h"
#include <QObject>
#include <QList>
#include "obstacle.h"
#define Bulletwidth 5
#define Bulletheight 8
class Bullet :public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
