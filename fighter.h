#ifndef FIGHTER_H
#define FIGHTER_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#define Fighterheight 80
#define Fighterwidth 50
class Fighter : public QGraphicsRectItem
{
public:
    Fighter();
    void keyPressEvent(QKeyEvent *event);
};

#endif // FIGHTER_H
