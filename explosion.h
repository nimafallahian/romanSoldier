#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QObject>

class Explosion: public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Explosion(int width, int height);
public slots:
    void destruct();
private:
    QMediaPlayer * explosionSound;
    QTimer * timer;
};

#endif // EXPLOSION_H
