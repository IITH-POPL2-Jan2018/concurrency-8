#include "target.h"
#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>



target::target(gamestate *state_param)
{
    state = state_param;
    QPixmap tar(":/images/bug1.png");
    QPixmap scaled= tar.scaled(QSize(40,40));
    setPixmap(scaled);
    a = 0;
        // connect
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        timer->start(50);
}

target::target(int i, gamestate *state_param)
{
    state = state_param;
    QPixmap tar(":/images/bug1.png");
    QPixmap scaled= tar.scaled(QSize(40,40));
    setPixmap(scaled);
}

void target::move()
{
    if(a == 0){
        setPos(x(),y()-10);
        if (pos().y()  <=  0){
            setTransformOriginPoint(20,20);
            setRotation(180);
            a = 1;
        }
    }
    else if(a == 1){
        setPos(x(),y()+10);
        if (pos().y() + 60  >=  600){
            setTransformOriginPoint(20,20);
            setRotation(0);
            a = 0;
        }
    }
    state->TargetPosition.setX(pos().x());
    state->TargetPosition.setY(pos().y());
}
