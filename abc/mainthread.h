#ifndef MAINTHREAD_H
#define MAINTHREAD_H
#include <QGraphicsScene>
#include "gamestate.h"
#include "myplayer1.h"
#include "target.h"
#include "score.h"
#include <QThread>

class mainThread : public QThread
{
public:
    QGraphicsScene * scene;
    score * points;
    gamestate * state;
    myplayer1 * p1;
    target * t;
    mainThread(QGraphicsScene * scene_param,gamestate * state_param, score * points_param, myplayer1 * p1_param,target*t_param);
    void run();
};
#endif // MAINTHREAD_H
