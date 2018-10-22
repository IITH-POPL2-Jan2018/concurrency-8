#include "gamestate.h"
#include <QGraphicsScene>

gamestate::gamestate(QGraphicsScene * scene)
{
    stateScene = scene;
    isArrow1 = false;
    isArrow2 = false;
}

QJsonObject gamestate::getJsonObject()
{
    QJsonObject tmp {

            {"player1_posX",Player1Position.x()},
            {"player1_posY",Player1Position.y()},
            {"player2_posX",Player2Position.x()},
            {"player2_posY",Player2Position.y()},
            {"target_posX",TargetPosition.x()},
            {"target_posY",TargetPosition.y()},
            {"isArrow1",isArrow1},
            {"isArrow2",isArrow2},
            {"arrow1_posX",Arrow1Position.x()},
            {"arrow1_posY",Arrow1Position.y()},
            {"arrow2_posX",Arrow2Position.x()},
            {"arrow2_posY",Arrow2Position.y()},
            {"arrow1_angle",Arrow1Angle},
            {"arrow2_angle",Arrow2Angle},
            {"bow1_angle",Bow1Angle},
            {"bow2_angle",Bow2Angle}

    };

    return tmp;
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


