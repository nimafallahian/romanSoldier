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
    FirstButton();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    static Fighter * onlyFighter;
public slots:
    void STOP();
signals:
    void Resume();
};

#endif // FIRSTBUTTON_H
