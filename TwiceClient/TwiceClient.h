
// TwiceClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTwiceClientApp:
// �йش����ʵ�֣������ TwiceClient.cpp
//

class CTwiceClientApp : public CWinApp
{
public:
	CTwiceClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTwiceClientApp theApp;