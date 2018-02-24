#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsPixmapItem>

class myplayer1: public QGraphicsPixmapItem
{
public:
    myplayer1();
    void keyPressEvent(QKeyEvent * event);
};

#endif // MYPLAYER1_H
