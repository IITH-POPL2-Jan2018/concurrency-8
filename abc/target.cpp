#include "target.h"
#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>

int a = 0;
target::target()
{
    QPixmap tar(":/images/bug1.png");
    QPixmap scaled= tar.scaled(QSize(40,40));
    setPixmap(scaled);

        // connect
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
}

void target::move()
{
    if(a == 0){
        setPos(x(),y()-10);
        if (pos().y()  ==  0){
            a = 1;
        }
    }
    else if(a == 1){
        setPos(x(),y()+10);
        if (pos().y() + 60  ==  600){
            a = 0;
        }
    }
}
