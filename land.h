#ifndef LAND_H
#define LAND_H
#include <QGraphicsRectItem>
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
public slots:
    void moveV();
//    void moveH();
private:
    QVector <QGraphicsRectItem*> rects;
    int Vspeed;

};

#endif // LAND_H
