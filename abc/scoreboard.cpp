
#include <QGraphicsScene>
#include "scoreboard.h"

scoreboard::scoreboard()
{
    QPixmap play(":/images/target1.png");
    QPixmap scaled= play.scaled(QSize(35,35));
    setPixmap(scaled);
}
