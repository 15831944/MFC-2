#include "stdafx.h"
#include "Works.h"
#include "WorksDlg.h"
#include "MainDlg.h"

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

	while (true)
	{
		CMainDlg mainDlg;
		switch (mainDlg.DoModal())
		{
		case IDCANCEL:
			return FALSE;
			break;
		case IDC_INFO:
		{
			CWorksDlg dlg;
			dlg.DoModal();
		}
		case IDC_ADMIN:
		{

		}
		default:
			break;
		}
	}


	//CWorksDlg dlg;
	//nResponse = dlg.DoModal();

	return FALSE;
}

