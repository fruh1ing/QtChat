#include "Server.h"
#include "SetServer.h"

Server::Server(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.m_pbtnSetServer, &QPushButton::clicked, this, &Server::ClickSetServer);
	connect(ui.m_pbtnSendMsg, &QPushButton::clicked, this, &Server::ClickSendMsg);
}

Server::~Server()
{

}

void Server::OpenServer(const QString& ip, const QString& port)
{

}

void Server::ClickSetServer()
{
	SetServer* setserver = new SetServer(this);
	setserver->exec();
}

void Server::ClickSendMsg()
{

}
