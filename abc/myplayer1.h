#ifndef MYPLAYER1_H
#define MYPLAYER1_H

#include <QGraphicsPixmapItem>
#include "bow.h"
#include "arrow.h"
#include "gamestate.h"
#include "target.h"
#include <QWebSocket>

class myplayer1: public QGraphicsPixmapItem
{
public:
    bow * bow1;
    gamestate * state;
    target *t;
    arrow * player2Arrow;
    myplayer1(gamestate * state_param, target *t_param);
    myplayer1(int i , gamestate * state_param);
    void keyPressEvent(QKeyEvent * event);
    QWebSocket * client_local;
    void setClientLocal(QWebSocket * client_param);

};

#endif // MYPLAYER1_H
