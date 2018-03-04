#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsPixmapItem>
#include "bow.h"
#include "gamestate.h"
#include <QWebSocket>

class myplayer1: public QGraphicsPixmapItem
{
public:
    bow * bow1;
    gamestate * state;
    myplayer1(gamestate * state_param);
    myplayer1(int i , gamestate * state_param);
    void keyPressEvent(QKeyEvent * event);
    QWebSocket * client_local;
    void setClientLocal(QWebSocket * client_param);

};

#endif // MYPLAYER1_H
