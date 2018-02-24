#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsPixmapItem>
#include <QObject>

class arrow: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    arrow();
public slots:
    void move();
};

#endif // ARROW_H
