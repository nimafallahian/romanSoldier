#ifndef LAND_H
#define LAND_H
#include <QGraphicsItem>
#include <QVector>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
class Land : public QObject
{
    Q_OBJECT
public:
    Land(bool RL , int width , int height,int gateWidth,QGraphicsScene* scene);
    Land(int width , int height , QGraphicsScene* scene);
    QTimer *Vtimer;
    bool InOut();
    bool Inview();
    bool nextOne;
public slots:
    void moveV();
    void speedUP();
    void speedDOWN();
    void speedNORMAL();
    void STOP();
    void RESUME();
//    void moveH();
private:
    QVector <QGraphicsItem*> rects;
    int Vspeed;
    int normalVspeed ;     //Vertical speed
    int incVspeed ;
    int decVspeed ;
signals:
    void end();
    void Stop();
};

#endif // LAND_H
