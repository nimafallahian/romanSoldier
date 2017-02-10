#ifndef FIRSTBUTTON_H
#define FIRSTBUTTON_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include "fighter.h"

class FirstButton: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    FirstButton(Fighter * onlyFighter);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Fighter * onlyFighter;
public slots:
    void STOP();
signals:
    void Resume();
};

#endif // FIRSTBUTTON_H
