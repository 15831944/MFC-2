
// lesson03-TestMeg.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "lesson03-TestMeg.h"
#include "lesson03-TestMegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson03TestMegApp

BEGIN_MESSAGE_MAP(Clesson03TestMegApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Clesson03TestMegApp 构造

Clesson03TestMegApp::Clesson03TestMegApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Clesson03TestMegApp 对象

Clesson03TestMegApp theApp;


// Clesson03TestMegApp 初始化

BOOL Clesson03TestMegApp::InitInstance()
{
	Clesson03TestMegDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

