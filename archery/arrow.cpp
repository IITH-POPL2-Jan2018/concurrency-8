
#include "arrow.h"
#include <QTimer>
#include <QGraphicsScene>

arrow::arrow()
{
    QPixmap arro(":/img/arrow8.jpg");
    QPixmap scaled= arro.scaled(QSize(60,40));
    setPixmap(scaled);


    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(80);
}

void arrow::move(){
    // move arrow right
    setPos(x()+10,y());
    if (pos().x() > 485)
    {
        scene()->removeItem(this);
        delete this;
    }
}
