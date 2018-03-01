#include "myplayer1.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <qmath.h>
#include "arrow.h"
#include "bow.h"
extern int flag;
myplayer1::myplayer1(gamestate *state_param)
{
    state = state_param;
    QPixmap play(":/images/arrow2.png");
    QPixmap scaled= play.scaled(QSize(150,100));
    setPixmap(scaled);
    bow * b = new bow();
    state->Bow1Angle = 0;
    b->setPos(x(),y());
    bow1 = b;
    flag=0;
}

myplayer1::myplayer1(int i)
{
    QPixmap play(":/images/arrow_flip.png");
    QPixmap scaled= play.scaled(QSize(150,100));
    setPixmap(scaled);
}


void myplayer1::keyPressEvent(QKeyEvent *event)
{

       if (event->key() == Qt::Key_Up)
       {
           if (pos().y() > 30){
               setPos(x(),y()-10);
               bow1->setPos(x()+60,y()+10);
           }
       }
       else if (event->key() == Qt::Key_Down)
       {
           if (pos().y() < 470)
           setPos(x(),y()+10);
           bow1->setPos(x()+60,y()+10);
       }
       else if (event->key() == Qt::Key_Right)
       {
           if(bow1->angle <= 30)
           {
               bow1->setTransformOriginPoint(0,22.5);
               bow1->angle += 5;
               bow1->setRotation(bow1->angle);
           }
       }
       else if (event->key() == Qt::Key_Left)
       {
           if(bow1->angle >= -30)
           {
              bow1->setTransformOriginPoint(0,22.5);
               bow1->angle -= 5;
               bow1->setRotation(bow1->angle);
           }
       }
       else if ((event->key() == Qt::Key_Space)&& flag==0)
       {
           // create an arrow

            arrow * a = new arrow(state);
            state->isArrow1 = true;
            a->angle = bow1->angle;
            a->presentAngle = bow1->angle;
            a->setRotation(a->angle);
            state->Arrow1Angle = a->angle;
            a->setPos(bow1->x()+50*qCos(qDegreesToRadians(a->angle)),bow1->y()+50*qSin(qDegreesToRadians(a->angle)) +10);
            state->Arrow1Position.setX(a->x());
            state->Arrow1Position.setY(a->y());
            a->initialX = bow1->x()+50*qCos(qDegreesToRadians(a->angle));
            a->initialY = bow1->y()+50*qSin(qDegreesToRadians(a->angle)) + 10;
            scene()->addItem(a);
            flag=1;
       }
       state->Player1Position.setX(x());
       state->Player1Position.setY(y());
       state->Bow1Angle = bow1->angle;

}
