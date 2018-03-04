#ifndef CLIENT_H
#define CLIENT_H

#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include "gamestate.h"

class client : public QObject
{
    Q_OBJECT
public :
    gamestate * state;
    client(gamestate * state_param);
    void estServerConnection(QUrl url_param);

private :
    QWebSocket Client_local;
    QUrl Server_url;

private slots:
    void connectionSetup();
    void processText(QString text);
    void processBinary(QByteArray message_bytes);
};

#endif // CLIENT_H
