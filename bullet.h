#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include <QTimer>
#include <QMediaPlayer>
#include "explosion.h"
#define Bulletwidth 5
#define Bulletheight 8
class Bullet :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
private:
    QTimer * timer;
};

#endif // BULLET_H
