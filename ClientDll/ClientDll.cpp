// ClientDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ClientDll.h"


// ���ǵ���������һ��ʾ��
CLIENTDLL_API int nClientDll=0;

// ���ǵ���������һ��ʾ����
CLIENTDLL_API int fnClientDll(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ClientDll.h
CClientDll::CClientDll()
{
	return;
}
