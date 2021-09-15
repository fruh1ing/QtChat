#pragma once

#include <QtWidgets/QWidget>
#include "ui_Server.h"

class Server : public QWidget
{
	Q_OBJECT

public:
	Server(QWidget* parent = Q_NULLPTR);
	~Server();

	void OpenServer(const QString& ip, const QString& port);

private:
	Ui::ServerClass ui;


private slots:
	void ClickSetServer();
	void ClickSendMsg();
};
