#ifndef FIGHTER_H
#define FIGHTER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>

#define Fighterheight 100
#define Fighterwidth 62
class Fighter : public QGraphicsPixmapItem
{
public:
    Fighter();
    void keyPressEvent(QKeyEvent *event);
private:
    QMediaPlayer * bulletsound;
};

#endif // FIGHTER_H
