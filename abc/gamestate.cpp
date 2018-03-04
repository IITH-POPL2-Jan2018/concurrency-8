#include "gamestate.h"
gamestate::gamestate(QGraphicsScene *scene)
{
    stateScene = scene;
    isArrow1 = false;
    isArrow2 = false;
}

/*void gamestate::StateSet(myplayer1 *p1, myplayer1 *p2, target *t)
{
    Player1Position.setX(p1->x());
    Player1Position.setY(p1->y());
    Player2Position.setX(p2->x());
    Player2Position.setY(p2->y());
    TargetPosition.setX(t->x());
    TargetPosition.setY(t->y());

}*/


