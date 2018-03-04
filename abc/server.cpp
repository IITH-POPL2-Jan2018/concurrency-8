
#include "server.h"


server::server(QGraphicsScene scene_param, quint16 port_param)
{
    port=port_param;
    server_local=new QWebSocketServer(QStringLiteral("Archery Server"),QWebSocketServer::NonSecureMode,this)
}


