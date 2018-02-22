#include "myplayer1.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "arrow.h"

void myplayer1::keyPressEvent(QKeyEvent *event)
{

       if (event->key() == Qt::Key_Up)
       {
           setPos(x(),y()-10);
       }
       else if (event->key() == Qt::Key_Down)
       {
           setPos(x(),y()+10);
       }
       else if (event->key() == Qt::Key_Space)
       {
           // create an arrow
            arrow * a = new arrow();
            a->setPos(x()+100,y()+25);
            scene()->addItem(a);
       }
}
