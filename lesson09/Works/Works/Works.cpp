#include "stdafx.h"
#include "Works.h"
#include "WorksDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CWorksApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CWorksApp::CWorksApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CWorksApp theApp;

BOOL CWorksApp::InitInstance()
{
	CWorksDlg dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

