#include "myplayer1.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "arrow.h"

myplayer1::myplayer1()
{
    QPixmap play(":/images/arrow.png");
    QPixmap scaled= play.scaled(QSize(150,100));
    setPixmap(scaled);
}

void myplayer1::keyPressEvent(QKeyEvent *event)
{

       if (event->key() == Qt::Key_Up)
       {
           if (pos().y() > 30)
            setPos(x(),y()-10);
       }
       else if (event->key() == Qt::Key_Down)
       {
           if (pos().y() < 470)
           setPos(x(),y()+10);
       }
       else if (event->key() == Qt::Key_Space)
       {
           // create an arrow
            arrow * a = new arrow();
            a->setPos(x()+100,y()+20);
            scene()->addItem(a);
       }
}
