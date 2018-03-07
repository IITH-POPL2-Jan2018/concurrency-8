#ifndef SERVER_H
#define SERVER_H
#include <QWebSocketServer>
#include <QWebSocket>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "gamestate.h"
#include "target.h"


class server: public QObject{
    Q_OBJECT

   private:

    const quint16 port;
    QWebSocketServer * server_local;
    QWebSocket * client_local;
    bool gameStarted;
    bool loop_Running;
    QGraphicsScene * scene;
    QGraphicsView * view;
    gamestate * state;
    void startGame();
    target *t;

   private Q_SLOTS:

    void connectionSetup();
    void processText(QString text);
    void processBinary(QByteArray binary);
    void sendGameState();

   public:

    server(QGraphicsScene * scene_param,QGraphicsView * view_param,quint16 port_param,gamestate * state_param, target *t_param);
    void startServer();
    void gameLoop();

};

#endif // SERVER_H
