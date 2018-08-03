#include "stdafx.h"
#include "TestRegistryKey.h"
#include "TestRegistryKeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CTestRegistryKeyApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CTestRegistryKeyApp::CTestRegistryKeyApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestRegistryKeyApp theApp;

BOOL CTestRegistryKeyApp::InitInstance()
{
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CTestRegistryKeyDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

