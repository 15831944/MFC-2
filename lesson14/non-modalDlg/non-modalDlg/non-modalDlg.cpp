#include "stdafx.h"
#include "non-modalDlg.h"
#include "non-modalDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
BEGIN_MESSAGE_MAP(CnonmodalDlgApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CnonmodalDlgApp::CnonmodalDlgApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CnonmodalDlgApp theApp;

BOOL CnonmodalDlgApp::InitInstance()
{
	CnonmodalDlgDlg dlg;

	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

