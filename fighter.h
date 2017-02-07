#ifndef FIGHTER_H
#define FIGHTER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QObject>

#define Fighterheight 100
#define Fighterwidth 62
class Fighter : public QObject ,public QGraphicsPixmapItem
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
private:
    QMediaPlayer * bulletsound;
};

#endif // FIGHTER_H
