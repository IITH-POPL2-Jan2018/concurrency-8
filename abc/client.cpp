#include "client.h"
#include <QDebug>

client::client(gamestate *state_param)
{
    state = state_param;
}

void client::estServerConnection(QUrl url_param)
{
    Server_url = url_param;
    connect(&Client_local,&QWebSocket::connected, this, &client::connectionSetup);
    Client_local.open(Server_url);
}

void client::connectionSetup()
{
    connect(&Client_local, &QWebSocket::textMessageReceived,this,&client::processText);
    connect(&Client_local, &QWebSocket::binaryMessageReceived,this,&client::processBinary);
}

void client::processText(QString text)
{
    if(text.contains("Are You Ready ?"))
    {
        Client_local.sendTextMessage("Yes");
    }
}

void client::processBinary(QByteArray message_bytes)
{
    QJsonDocument message_doc = QJsonDocument::fromBinaryData(message_bytes);
    QJsonObject message = message_doc.object();
   // state->Player1Position.setX(message["player1_posX"].toInt());
   // state->Player1Position.setY(message["player1_posY"].toInt());
    state->Player2Position.setX(message["player2_posX"].toInt());
    state->Player2Position.setY(message["player2_posY"].toInt());
    state->TargetPosition.setX(message["target_posX"].toInt());
    state->TargetPosition.setY(message["target_posY"].toInt());
   // state->isArrow1 = message["isArrow1"].toBool();
    state->isArrow2 = message["isArrow2"].toBool();
   /* if(state->isArrow1)
    {
        state->Arrow1Position.setX(message["arrow1_posX"].toInt());
        state->Arrow1Position.setY(message["arrow1_posY"].toInt());
        state->Arrow1Angle = (message["arrow1_angle"].toDouble());
    } I*/
    if(state->isArrow2)
    {
        state->Arrow2Position.setX(message["arrow2_posX"].toInt());
        state->Arrow2Position.setY(message["arrow2_posY"].toInt());
        state->Arrow2Angle = (message["arrow2_angle"].toDouble());
    }
    //state->Bow1Angle = (message["bow1_angle"].toDouble());
    state->Bow2Angle = (message["bow2_angle"].toDouble());
}
