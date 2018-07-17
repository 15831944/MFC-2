#include "stdafx.h"
#include "MamyTest.h"
#include "MamyTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CMamyTestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CMamyTestApp::CMamyTestApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CMamyTestApp theApp;

BOOL CMamyTestApp::InitInstance()
{
	CMamyTestDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

