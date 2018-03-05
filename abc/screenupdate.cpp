#include "screenupdate.h"
#include <QTimer>

screenUpdate::screenUpdate(QGraphicsScene *scene_param, gamestate *state_param , myplayer1 * p1_param, myplayer1 * p2_param , target * t_param,int i)
{
    scene_local = scene_param;
    state = state_param;
    id = i;
    p1 = p1_param;
    p2 = p2_param;
    t = t_param;
}

void screenUpdate::startUpdate()
{
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(50);
}

void screenUpdate::Update()
{
    p2->setPos(state->Player2Position.x(),state->Player2Position.y());
    p2->bow1->setPos(740,state->Player2Position.y() + 55 );
    p2->bow1->setRotation(state->Bow2Angle);
    if(id == 1)
    {
        t->setPos(state->TargetPosition.x(),state->TargetPosition.y());
    }
    if(state->isArrow2)
    {
        p2->player2Arrow->setPos(state->Arrow2Position.x(),state->Arrow2Position.y());
        p2->player2Arrow->setRotation(state->Arrow2Angle);
        if(!p2->player2Arrow->isVisible())
            p2->player2Arrow->show();
    }
    else
    {
        if(p2->player2Arrow->isVisible())
            p2->player2Arrow->hide();
    }
}

