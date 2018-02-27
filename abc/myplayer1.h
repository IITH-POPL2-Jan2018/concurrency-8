#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsPixmapItem>
#include "bow.h"

class myplayer1: public QGraphicsPixmapItem
{
public:
    bow * bow1;
    myplayer1();
    myplayer1(int i);
    void keyPressEvent(QKeyEvent * event);

};

#endif // MYPLAYER1_H
