#ifndef SCREENUPDATE_H
#define SCREENUPDATE_H

#include <QGraphicsScene>
#include "gamestate.h"
#include "myplayer1.h"
#include "target.h"
#include <QObject>

class screenUpdate : public QObject{
    Q_OBJECT
public:

    QGraphicsScene * scene_local;
    int id;
    myplayer1 * p1;
    myplayer1 * p2;
    target * t;
    gamestate * state;
    screenUpdate(QGraphicsScene * scene_param,gamestate * state_param , myplayer1 * p2_param,int i);
    void startUpdate();
private Q_SLOTS:
    void Update();


};
#endif // SCREENUPDATE_H
