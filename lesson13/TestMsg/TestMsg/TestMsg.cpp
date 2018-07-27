#include "stdafx.h"
#include "TestMsg.h"
#include "TestMsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CTestMsgApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CTestMsgApp::CTestMsgApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestMsgApp theApp;

BOOL CTestMsgApp::InitInstance()
{
	CTestMsgDlg dlg;

	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

