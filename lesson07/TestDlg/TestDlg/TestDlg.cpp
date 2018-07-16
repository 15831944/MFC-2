#include "stdafx.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CTestDlgApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CTestDlgApp::CTestDlgApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestDlgApp theApp;

BOOL CTestDlgApp::InitInstance()
{
	CTestDlgDlg dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

