
// TwiceClientDlg.h : ͷ�ļ�
//

#pragma once


// CTwiceClientDlg �Ի���
typedef void (_cdecl *ServiceFunc)(char *serviceName);

class CTwiceClientDlg : public CDialogEx
{
// ����
public:
	CTwiceClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TWICECLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HMODULE m_hDll;     //handle for loaded dll
	ServiceFunc m_fService;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
