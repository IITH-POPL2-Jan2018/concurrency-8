#include "bow.h"

bow::bow()
{
    QPixmap b(":/images/bow.png");
    QPixmap scaled= b.scaled(QSize(70,45));
    setPixmap(scaled);
    angle = 0;
}

/*bow::bow(int i)
{
    QPixmap b(":/images/bow_flip.png");
    QPixmap scaled= b.scaled(QSize(70,45));
    setPixmap(scaled);
    angle = 0;
}*/
