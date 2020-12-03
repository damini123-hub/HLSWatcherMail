#pragma once

#include <afxwin.h>

#pragma warning(disable : 4996)

typedef struct stMAIL
{
	char To[100][MAX_PATH];
	char From[MAX_PATH];
	char SMTP[MAX_PATH];
	char UserName[MAX_PATH];
	char Password[MAX_PATH];
	char Subject[4500];
	char Text[4500];
	char HeaderText[MAX_PATH];
}
MAIL;

typedef struct stHLSMonitor
{
	bool bHLSMonitor;
	TCHAR strMonitorMsg[MAX_PATH];

}HLSMONITOR;

class AlertMail
{
public:
	AlertMail();

	MAIL Mail;
	int MailCount;
	int m_nAlertDurationTime;
	int m_nDetectionTime;
	int m_nTotalEmailId;
	TCHAR m_strUserName[100];
	TCHAR m_strPassword[100];
	TCHAR m_strReceiverEmailId[10][100];
	TCHAR m_strSMTP[100];
	TCHAR m_strSystemName[100];

	void ReadEmailConfiguration();
	void SendData(HLSMONITOR monitor);
	void SendMail();

};

extern HLSMONITOR hlsmonitor;


