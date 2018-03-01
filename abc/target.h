#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>
#include "gamestate.h"

#include <QObject>
class target: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    gamestate * state;
    target(gamestate * state_param);
    int a;
public slots:
    void move();

};
#endif // TARGET_H
