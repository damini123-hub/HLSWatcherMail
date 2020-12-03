// HLSWatcherMail.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HLSWatcherMail.h"

int main()
{
	memset(&hlsmonitor, 0, sizeof(HLSMONITOR));
	memset(&hlsmonitorparams, 0, sizeof(HLSMONITORPARAMS));
	m_AlertMail.ReadEmailConfiguration();

	hlsmonitorparams.bStartMonitor = true;
	hlsmonitorparams.m_LastAlertTime = GetTickCount();
	hHLSMonitor = CreateThread(NULL, 0, 0, HLSMonitorThread, 0, 0);
    return 0;
}

DWORD WINAPI HLSMonitorThread()
{
	while (hlsmonitorparams.bStartMonitor)
	{
		DWORD nTimeDiffAlert = GetTickCount() - hlsmonitorparams.m_LastAlertTime;
		if (nTimeDiffAlert > m_AlertMail.m_nAlertDurationTime)
		{
			hlsmonitorparams.bLastAlert = true;
			hlsmonitorparams.m_LastAlertTime = GetTickCount();
		}

		if (hlsmonitorparams.bLastAlert)
		{
			hlsmonitorparams.bLastAlert = false;
			int nCurrentTime = GetTickCount() - hlsmonitorparams.m_LastUpdateTime;

			if (hlsmonitor.bHLSMonitor == false)
			{
				if (nCurrentTime > m_AlertMail.m_nDetectionTime)
				{
					hlsmonitor.bHLSMonitor = true;
					_stprintf(hlsmonitor.strMonitorMsg, _T("Chunks stopped getting downloaded"));
					m_AlertMail.SendData(hlsmonitor);
				}
			}
			else
			{
				if (nCurrentTime == 0)
				{
					hlsmonitor.bHLSMonitor = false;
					_stprintf(hlsmonitor.strMonitorMsg, _T("Chunks start getting downloaded"));
					m_AlertMail.SendData(hlsmonitor);
				}
			}
		}

		Sleep(1000);
	}

	return 1;

}
