#include "mainthread.h"
#include "myplayer1.h"
#include "target.h"
#include "score.h"
#include "scoreboard.h"

mainThread::mainThread(QGraphicsScene *scene_param, gamestate *state_param, score *points_param,myplayer1 * p1_param,target * t_param)
{
    scene = scene_param;
    state = state_param;
    points = points_param;
    p1 = p1_param;
    t = t_param;
    run1();
}

void mainThread::run1()
{
    t = new target(state);
    scene->addItem(t);
    p1 = new myplayer1(state,t);
    scene->addItem(p1);
    scene->addItem(p1->bow1);
    // make rect focusable
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scoreboard * s =new scoreboard();
    scene->addItem(s);
    //points = new score();
    scene->addItem(points);
    p1->setPos(0,200);
    p1->bow1->setPos(60,210);
    s->setPos(200,0);
    t->setPos(800/2,600-60);
    //state->StateSet(p1,p2,t);
    state->Player1Position.setX(p1->x());
    state->Player1Position.setY(p1->y());
    state->TargetPosition.setX(t->x());
    state->TargetPosition.setY(t->y());
    state->Bow1Angle = 0;
    state->Arrow1Angle =0;
}
