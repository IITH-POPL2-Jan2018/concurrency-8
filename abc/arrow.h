#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "gamestate.h"
#include "target.h"

class arrow: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    gamestate * state;
    target *t;
    arrow(gamestate * state_param, target *t_param);
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
