#ifndef SERVER_H
#define SERVER_H
#include <QWebSocketServer>
#include <QWebSocket>
#include <QObject>
#include <QGraphicsScene>
#include "gamestate.h"


class server :
{
    Q_OBJECT

   private:

    const quint16 port;
    QWebSocketServer * server_local;
    QWebSocket * client_local;
    bool gameStarted;
    bool loop_Running;
    QGraphicsScene * scene;
    gamestate * state;
    void startGame();

   private Q_SLOTS:

    void connectionSetup();
    void gameLoop();
    void processText();
    void processBinary();

   public:

    server(QGraphicsScene scene_param,quint16 port_param);
    void startServer();

}

#endif // SERVER_H
