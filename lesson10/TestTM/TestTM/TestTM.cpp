#include "stdafx.h"
#include "TestTM.h"
#include "TestTMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CTestTMApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CTestTMApp::CTestTMApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestTMApp theApp;

BOOL CTestTMApp::InitInstance()
{
	
	CTestTMDlg dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

