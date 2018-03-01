#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsPixmapItem>
#include "bow.h"
#include "gamestate.h"

class myplayer1: public QGraphicsPixmapItem
{
public:
    bow * bow1;
    gamestate * state;
    myplayer1(gamestate * state_param);
    myplayer1(int i);
    void keyPressEvent(QKeyEvent * event);

};

#endif // MYPLAYER1_H
