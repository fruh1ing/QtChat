#include "SetServer.h"
#include "ui_SetServer.h"
#include <QSettings>
#include <QMessageBox>

SetServer::SetServer(QWidget* parent)
	: QDialog(parent)
{
	ui = new Ui::SetServer();
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose, true);

	//读取IP和Port
	QString path = CONFGPATH;
	path += "ServerConfig.ini";
	QSettings* ConfigRead = new QSettings(path, QSettings::IniFormat);
	QString ipResult = ConfigRead->value("ServerConfig/IP").toString();
	QString portResult = ConfigRead->value("ServerConfig/Port").toString();
	delete ConfigRead;
	if (ipResult == "" || ipResult == NULL)
	{
		ipResult = "127.0.0.1";
		portResult = "12306";
	}
	ui->m_editServerIP->setText(ipResult);
	ui->m_editServerPort->setText(portResult);
	server = (Server*)this->parentWidget();
	connect(ui->m_pbtnConfirm, &QPushButton::clicked, this, &SetServer::ClickConfirm);
}

SetServer::~SetServer()
{
	delete ui;
}

void SetServer::ClickConfirm()
{
	m_ip = ui->m_editServerIP->text();
	m_port = ui->m_editServerPort->text();
	if (m_ip == "" || m_port == "")
	{
		QMessageBox::warning(NULL, "warning", "IP or Port is None", "OK");
		return;
	}
	server->OpenServer(m_ip, m_port);
	this->close();
}
