
// lesson05.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "lesson05.h"
#include "lesson05Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(Clesson05App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

Clesson05App::Clesson05App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

Clesson05App theApp;
/********************************************************
	part 1	The composition of MFC
	1)	There must be a CWinApp derive class
	2)	Must use theApp derive class defiend in the global object
	3)	Must in the derive class override InitInstance virtual functions
	4)	MFC program with CWinApp Instance virtual function as the main function in a derive class

********************************************************/

/********************************************************
	part 2	MFC对话框程序的消息处理
	1)	为一个对话框模板建立一个与之关联的CDialog或CDialogEx派生类
	2)	
	3)	Must in the derive class override InitInstance virtual functions
	4)	MFC program with CWinApp Instance virtual function as the main function in a derive class

********************************************************/
BOOL Clesson05App::InitInstance()
{
	Clesson05Dlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	return FALSE;
}

