#include "stdafx.h"
#include "Works.h"
#include "WorksDlg.h"
#include "MainDlg.h"
#include "AdminDlg.h"
#include "InputDlg.h"
#include "Login.h"
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

/***********************************************
part 1 dlg.Domodal()的返回值
	1)	EndDialog(ID编号)
		DoModal()的返回值 == ID编号
***********************************************/
BOOL CWorksApp::InitInstance()
{
	CLogin dlg;
	if (IDCANCEL == dlg.DoModal())
		return FALSE;
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
		break;
		case IDC_ADMIN:
		{
			CAdminDlg dlg;
			dlg.DoModal();
		}
		case IDC_LOGIN:
		{
			CLogin redlg;
			if (redlg.DoModal() == IDCANCEL)
				return FALSE;
		}
		break;
		default:
			break;
		}
	}


	//CWorksDlg dlg;
	//nResponse = dlg.DoModal();

	return FALSE;
}

