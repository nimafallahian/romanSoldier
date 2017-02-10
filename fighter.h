#ifndef FIGHTER_H
#define FIGHTER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QObject>
#include <QTimer>
//#include "firstbutton.h"
#include "fuel.h"
#define Fighterheight 100
#define Fighterwidth 62
class Fighter : public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fighter();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void emitRes();
    Fuel* fuelPack;
    QTimer* timer;
    bool isEmpty();
public slots:
    void emitStop();
    void decFuel();
    void incFuel();
    void stopFuel();
    void resumeFuel();

signals:
    void speedNormal();
    void speedUp();
    void speedDown();
    void Stop();
    void Resume();
private:
    QMediaPlayer * bulletsound;
//    FirstButton *but;
};

#endif // FIGHTER_H
