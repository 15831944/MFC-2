#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CNotepadApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


CNotepadApp::CNotepadApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CNotepadApp theApp;

BOOL CNotepadApp::InitInstance()
{
	CNotepadDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

