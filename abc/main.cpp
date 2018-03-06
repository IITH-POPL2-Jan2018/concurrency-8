#include <QApplication>
#include "target.h"
#include "myplayer1.h"
#include "score.h"
#include "scoreboard.h"
#include <QGraphicsScene>
#include "gamestate.h"
//#include <QPointF>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QJsonObject>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QJsonValue>
#include "screenupdate.h"
#include "server.h"
#include "client.h"
#include <QTimer>
#include "mainthread.h"
#include <QThread>

score * points ;
int flag;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    gamestate * state = new gamestate(scene);
    points = new score();
    myplayer1 * p1;
    target * t;
    int x = 0;
    if(x == 0)
    {
    QThread * thread1 = new QThread();
    thread1->start();
    mainThread * threadclass = new mainThread(scene,state,points,p1,t);
    threadclass->moveToThread(thread1);
    //thread->start();

    // create an item to add to the scene
   // myplayer1 * p1 = new myplayer1(state);

    myplayer1 * p2 = new myplayer1(1,state);
    // add the item to the scene
    /*scene->addItem(p1);
    scene->addItem(p1->bow1);*/
    scene->addItem(p2);
    scene->addItem(p2->bow1);
    scene->addItem(p2->player2Arrow);
   // target * t = new target(state);
    //target * t = new target(1,state);
    //scene->addItem(t);
    // make rect focusable
    /*p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scoreboard * s =new scoreboard();
    scene->addItem(s);
    points = new score();
    scene->addItem(points);*/

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.resized.jpeg")));
   /* p1->setPos(0,200);
    p1->bow1->setPos(60,210);*/
    p2->setPos(730,200);
    p2->bow1->setPos(715,200);
    p2->bow1->setRotation(180);
    /*s->setPos(200,0);
    t->setPos(view->width()/2,view->height()-60);
    //state->StateSet(p1,p2,t);
    state->Player1Position.setX(p1->x());
    state->Player1Position.setY(p1->y());*/
    state->Player2Position.setX(p2->x());
    state->Player2Position.setY(p2->y());
   /* state->TargetPosition.setX(t->x());
    state->TargetPosition.setY(t->y());
    state->Bow1Angle = 0;
    state->Arrow1Angle =0;*/
    state->Bow2Angle = 180;
    state->Arrow2Angle = 180;
    server * GameServer = new server(scene,1234,state);
    GameServer->startServer();
    //client * GameClient  = new client(state);
    //GameClient->estServerConnection(QUrl("ws://ip:1234"));
    screenUpdate * u = new screenUpdate(scene,state,p2,0);
    u->startUpdate();
    }
    else
    {
       /* QThread * thread1 = new QThread();
        thread1->start();
        mainThread * threadclass = new mainThread(scene,state,points,p1,t);
        threadclass->moveToThread(thread1);*/
        //thread->start();

        // create an item to add to the scene
        p1 = new myplayer1(state,t);

        myplayer1 * p2 = new myplayer1(1,state);
        // add the item to the scene
        scene->addItem(p1);
        scene->addItem(p1->bow1);
        scene->addItem(p2);
        scene->addItem(p2->bow1);
        scene->addItem(p2->player2Arrow);
       // target * t = new target(state);
        t = new target(1,state);
        scene->addItem(t);
        // make rect focusable
        p1->setFlag(QGraphicsItem::ItemIsFocusable);
        p1->setFocus();
        scoreboard * s =new scoreboard();
        scene->addItem(s);
        //points = new score();
        scene->addItem(points);

        // create a view to visualize the scene
        QGraphicsView * view = new QGraphicsView(scene);

        // show the view
        view->show();
        view->setFixedSize(800,600);
        scene->setSceneRect(0,0,800,600);
        scene->setBackgroundBrush(QBrush(QImage(":/images/bg.resized.jpeg")));
        p1->setPos(0,200);
        p1->bow1->setPos(45,200);
        p2->setPos(700,200);
        p2->bow1->setPos(655,200);
        p2->bow1->setRotation(180);
        s->setPos(200,0);
        t->setPos(view->width()/2,view->height()-60);
        //state->StateSet(p1,p2,t);
        state->Player1Position.setX(p1->x());
        state->Player1Position.setY(p1->y());
        state->Player2Position.setX(p2->x());
        state->Player2Position.setY(p2->y());
        state->TargetPosition.setX(t->x());
        state->TargetPosition.setY(t->y());
        state->Bow1Angle = 0;
        state->Arrow1Angle =0;
        state->Bow2Angle = 180;
        state->Arrow2Angle = 180;
        //server * GameServer = new server(scene,1234,state);
        //GameServer->startServer();
        client * GameClient  = new client(state);
        GameClient->estServerConnection(QUrl("ws://192.168.116.133:1234"));
        screenUpdate * u = new screenUpdate(scene,state,p2,1,t);
        u->startUpdate();
    }
    return a.exec();
}
