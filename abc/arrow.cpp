#include "arrow.h"
#include "score.h"
#include <QTimer>
#include <QtCore/qglobal.h>
#include <QTime>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include "target.h"
#include "myplayer1.h"
#include <typeinfo>
#include <QDebug>

extern score * points;
extern int flag;

arrow::arrow(gamestate *state_param)
{
    state = state_param;
    QPixmap arro(":/images/a1.png");
    QPixmap scaled= arro.scaled(QSize(40,25));
    setPixmap(scaled);

    time=0;
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(75);
}

void arrow::move(){
    time += 0.3;
    // move arrow right
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(target)){
                target * t = dynamic_cast<target*>(colliding_items[i]);
                // remove them both
                //scene()->removeItem(colliding_items[i]);
                points-> increase();
                scene()->removeItem(this);
                // delete them both
                //delete colliding_items[i];
                /*if(t && t->a == 1)
                {
                    t->a = 0;
                    t->setRotation(0);
                }*/
               // int random_number = (rand() % 500)+30;
                //colliding_items[i]->setPos(400,random_number);
                QTime time = QTime::currentTime();
                qsrand((uint)time.msec());
                colliding_items[i]->setPos(qrand()%100+350,qrand()%600);
                state->TargetPosition.setX(colliding_items[i]->x());
                state->TargetPosition.setY(colliding_items[i]->y());
                t->a = qrand()%2;
                if(t->a == 0)
                    t->setRotation(0);
                else
                    t->setRotation(180);
                delete this;
                state->isArrow1 = false;
                flag=0;
                return;
            }
        }

    presentAngle = qRadiansToDegrees(qAtan((75*qSin(qDegreesToRadians(-1*angle)) - 10*time)/(75*qCos(qDegreesToRadians(angle)))));
    setRotation(-1*presentAngle);
    state->Arrow1Angle = -1*presentAngle;
    double dy = 80 * qSin(qDegreesToRadians(-1*angle))*time-(5*(time*time));
    double dx = 80 * qCos(qDegreesToRadians(angle)) * time;
    setPos(initialX+dx,initialY-dy);
    state->Arrow1Position.setX(x());
    state->Arrow1Position.setY(y());
    if (pos().x() > 475)
    {
        scene()->removeItem(this);
        state->isArrow1 = false;
        delete this;
        flag=0;
    }
}
