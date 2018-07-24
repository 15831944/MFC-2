#include "stdafx.h"
#include "TestMeg.h"
#include "TestMegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CTestMegApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CTestMegApp::CTestMegApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestMegApp theApp;

BOOL CTestMegApp::InitInstance()
{
	CTestMegDlg dlg;

	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

