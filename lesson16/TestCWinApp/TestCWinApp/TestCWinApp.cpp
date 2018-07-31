
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
part 1 构造函数给基类初始化
	1) CTestCWinAppApp::CTestCWinAppApp():CWinApp(_T("温馨提示: "))
		AfxMessageBox(_T("TEST"));的标题都为(_T("温馨提示: "))
*************************************************/
/*************************************************
part 3 messagebox标题初始化
	1) 资源视图->添加->string table->变量:AFX_IDS_APP_TITLE
		定义标题
*************************************************/
CTestCWinAppApp::CTestCWinAppApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CTestCWinAppApp theApp;

BOOL CTestCWinAppApp::InitInstance()
{
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	AfxMessageBox(_T("TEST"));

	CTestCWinAppDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

