#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}



int Score::getScore(){
    return score;
}
void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}
