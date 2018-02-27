#include "myplayer1.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "arrow.h"
#include "bow.h"

myplayer1::myplayer1()
{
    QPixmap play(":/images/arrow2.png");
    QPixmap scaled= play.scaled(QSize(150,100));
    setPixmap(scaled);
    bow * b = new bow();
    b->setPos(x(),y());
    bow1 = b;

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
           if(bow1->angle <= 20)
           {
               bow1->setTransformOriginPoint(0,22.5);
               bow1->angle += 10;
               bow1->setRotation(bow1->angle);
           }
       }
       else if (event->key() == Qt::Key_Left)
       {
           if(bow1->angle >= -20)
           {
              bow1->setTransformOriginPoint(0,22.5);
               bow1->angle -= 10;
               bow1->setRotation(bow1->angle);
           }
       }
       else if (event->key() == Qt::Key_Space)
       {
           // create an arrow

            arrow * a = new arrow();
            a->angle = bow1->angle;
            a->setRotation(a->angle);
            a->setPos(bow1->x(),bow1->y()+10);
            scene()->addItem(a);
       }
}
