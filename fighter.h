#ifndef FIGHTER_H
#define FIGHTER_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#define Fighterheight 100
#define Fighterwidth 62
class Fighter :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Fighter();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void speedNormal();
    void speedUp();
    void speedDown();
    void Stop();
    void Resume();
};

#endif // FIGHTER_H
