
// lesson04-MFC������.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "lesson04-MFC������.h"
#include "lesson04-MFC������Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson04MFC������App

BEGIN_MESSAGE_MAP(Clesson04MFC������App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Clesson04MFC������App ����

Clesson04MFC������App::Clesson04MFC������App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Clesson04MFC������App ����

Clesson04MFC������App theApp;


// Clesson04MFC������App ��ʼ��

BOOL Clesson04MFC������App::InitInstance()
{

	Clesson04MFC������Dlg dlg;

	INT_PTR nResponse = dlg.DoModal();

	//���ش���ֵ	
	DWORD dwError = GetLastError();

	return FALSE;
}

