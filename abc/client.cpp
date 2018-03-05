#include "client.h"
#include <QDebug>
#include <QTimer>

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
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(sendGameState()));
        timer->start(50);
    }
}

void client::processBinary(QByteArray message_bytes)
{
    QJsonDocument message_doc = QJsonDocument::fromBinaryData(message_bytes);
    QJsonObject message = message_doc.object();
    state->Player2Position.setX(650);
    state->Player2Position.setY(message["player1_posY"].toInt());
   // state->Player2Position.setX(message["player2_posX"].toInt());
   // state->Player2Position.setY(message["player2_posY"].toInt());
    state->TargetPosition.setX(800 - message["target_posX"].toInt());
    state->TargetPosition.setY(message["target_posY"].toInt());
    state->isArrow2 = message["isArrow1"].toBool();
    //state->isArrow2 = message["isArrow2"].toBool();
    if(state->isArrow1)
    {
        state->Arrow2Position.setX(800 - message["arrow1_posX"].toInt());
        state->Arrow2Position.setY(message["arrow1_posY"].toInt());
        double angle  = message["arrow1_angle"].toDouble();
        if(angle < 0)
           state->Arrow2Angle = -(180 + angle);
        else
            state->Arrow2Angle = 180 - angle;
    }
    /*if(state->isArrow2)
    {
        state->Arrow2Position.setX(message["arrow2_posX"].toInt());
        state->Arrow2Position.setY(message["arrow2_posY"].toInt());
        state->Arrow2Angle = (message["arrow2_angle"].toDouble());
    }*/
    double angle = message["bow1_angle"].toDouble();
    if(angle < 0)
        state->Bow2Angle = (180 - angle);
    else
        state->Bow2Angle = 180 - angle;
    //state->Bow2Angle = (message["bow2_angle"].toDouble());
}

void client::sendGameState()
{
    QJsonObject message;
    message = state->getJsonObject();
    QJsonDocument message_doc(message);
    QByteArray message_byte = message_doc.toBinaryData();
    Client_local.sendBinaryMessage(message_byte);
}
