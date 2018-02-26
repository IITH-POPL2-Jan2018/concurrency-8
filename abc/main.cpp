#include <QApplication>
#include "target.h"
#include "myplayer1.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    myplayer1 * p1 = new myplayer1();

    // add the item to the scene
    scene->addItem(p1);

    target * t = new target();

    scene->addItem(t);
    // make rect focusable
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
        p1->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->show();
     view->setFixedSize(800,600);
     scene->setSceneRect(0,0,800,600);
     p1->setPos(0,200);
     t->setPos(view->width()/2,view->height() - 60);
    return a.exec();
}
