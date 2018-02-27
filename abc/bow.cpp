#include "bow.h"

bow::bow()
{
    QPixmap b(":/images/bow.png");
    QPixmap scaled= b.scaled(QSize(70,45));
    setPixmap(scaled);
    angle = 0;
}
