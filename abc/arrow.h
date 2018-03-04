#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "gamestate.h"

class arrow: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    gamestate * state;
    arrow(gamestate * state_param);
    arrow(int i);
    qreal angle;
    qreal presentAngle;
    qreal initialX;
    qreal initialY;
    qreal time;
public slots:
    void move();
};

#endif // ARROW_H
