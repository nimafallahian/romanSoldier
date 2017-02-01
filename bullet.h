#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "fighter.h"
#define Bulletwidth 5
#define Bulletheight 8
class Bullet : public QGraphicsRectItem
{
public:
    Bullet();
};

#endif // BULLET_H
