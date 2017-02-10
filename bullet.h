#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include <QTimer>
#include <QMediaPlayer>
#include "explosion.h"
#include "fighter.h"
#include "game.h"
#define Bulletwidth 5
#define Bulletheight 8
class Bullet :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int Vspeed;
    int normalSpeed;
    QTimer* timer;
public:
    Bullet(Fighter *);
public slots:
    void move();
    void STOP();
    void RESUME();
};

#endif // BULLET_H
