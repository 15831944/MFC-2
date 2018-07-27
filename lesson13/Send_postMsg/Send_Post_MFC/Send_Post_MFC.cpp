#include "stdafx.h"
#include "Send_Post_MFC.h"
#include "Send_Post_MFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CSend_Post_MFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CSend_Post_MFCApp::CSend_Post_MFCApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CSend_Post_MFCApp theApp;

BOOL CSend_Post_MFCApp::InitInstance()
{
	
	CSend_Post_MFCDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

