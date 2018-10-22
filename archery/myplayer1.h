#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsRectItem>

class myplayer1: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // MYPLAYER1_H
