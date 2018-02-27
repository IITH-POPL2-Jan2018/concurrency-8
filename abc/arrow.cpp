
#include "arrow.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include "target.h"
#include <typeinfo>

extern score * points;
arrow::arrow()
{
    QPixmap arro(":/images/a1.png");
    QPixmap scaled= arro.scaled(QSize(40,25));
    setPixmap(scaled);


    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(30);
}

void arrow::move(){
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
                if(t && t->a == 1)
                {
                    t->a = 0;
                    t->setRotation(0);
                }
                colliding_items[i]->setPos(400,540);
                delete this;
                return;
            }
        }
    double dy = 10 * qSin(qDegreesToRadians(angle));
    double dx = 10 * qCos(qDegreesToRadians(angle));
    setPos(x()+dx,y()+dy);
    if (pos().x() > 485)
    {
        scene()->removeItem(this);
        delete this;
    }
}
