#pragma once

#include <QDialog>
#include "Server.h"

#define  CONFGPATH "ServerConfig/" //保存配置文件的目录

namespace Ui { class SetServer; };

class SetServer : public QDialog
{
	Q_OBJECT

public:
	SetServer(QWidget* parent = Q_NULLPTR);
	~SetServer();

private slots:
	void ClickConfirm();

private:
	Ui::SetServer* ui;
	Server* server;
	QString m_ip;		//服务器IP
	QString m_port;	//服务器端口
};
