#ifndef SERVER_H
#define SERVER_H
#include <QWebSocketServer>
#include <QWebSocket>
#include <QObject>
#include <QGraphicsScene>
#include "gamestate.h"


class server: public QObject{
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
    void processText(QString text);
    void processBinary(QByteArray binary);
    void sendGameState();

   public:

    server(QGraphicsScene * scene_param,quint16 port_param,gamestate * state_param);
    void startServer();
    void gameLoop();

};

#endif // SERVER_H
