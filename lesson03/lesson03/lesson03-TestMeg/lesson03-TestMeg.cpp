
// lesson03-TestMeg.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "lesson03-TestMeg.h"
#include "lesson03-TestMegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson03TestMegApp

BEGIN_MESSAGE_MAP(Clesson03TestMegApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Clesson03TestMegApp ����

Clesson03TestMegApp::Clesson03TestMegApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Clesson03TestMegApp ����

Clesson03TestMegApp theApp;


// Clesson03TestMegApp ��ʼ��

BOOL Clesson03TestMegApp::InitInstance()
{
	Clesson03TestMegDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

