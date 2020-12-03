#pragma once

#include <afxwin.h>
#include "AlertMail.h"

typedef struct stHLSMonitorParams
{
	DWORD m_LastAlertTime;
	DWORD m_LastUpdateTime;
	bool bLastAlert;
	bool bStartMonitor;
}HLSMONITORPARAMS;

AlertMail m_AlertMail;
HLSMONITORPARAMS hlsmonitorparams;
HANDLE hHLSMonitor;
DWORD WINAPI HLSMonitorThread();