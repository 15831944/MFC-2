
#include "stdafx.h"
#include "TestCWinApp.h"
#include "TestCWinAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CTestCWinAppApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

/*************************************************
part 1 ���캯���������ʼ��
	1) CTestCWinAppApp::CTestCWinAppApp():CWinApp(_T("��ܰ��ʾ: "))
		AfxMessageBox(_T("TEST"));�ı��ⶼΪ(_T("��ܰ��ʾ: "))
*************************************************/
/*************************************************
part 3 messagebox�����ʼ��
	1) ��Դ��ͼ->���->string table->����:AFX_IDS_APP_TITLE
		�������
*************************************************/
CTestCWinAppApp::CTestCWinAppApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestCWinAppApp theApp;

BOOL CTestCWinAppApp::InitInstance()
{
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	AfxMessageBox(_T("TEST"));

	CTestCWinAppDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

