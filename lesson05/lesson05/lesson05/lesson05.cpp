
// lesson05.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "lesson05.h"
#include "lesson05Dlg.h"
#include "LoginDlg.h"
//#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/********************************************************
	part 5	MFC	六大技术之二 -> 消息处理机制
********************************************************/
BEGIN_MESSAGE_MAP(Clesson05App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

Clesson05App::Clesson05App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
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
	2)	在需要启动对话框用派生类定义一个对象, 在用对象调用DoModal成员函数
	3)	MFC如果要处理一个消息, 只要打开类向导, 选择在下拉中这个对话框类
	4)	在消息列表中就可以选择你需要的消息, 双击即可建立消息映射函数
	5)	消息映射函数就是: 一个消息(和一个窗口) 对应一个函数的地址

********************************************************/

/********************************************************
	part 4	MFC	六大技术之一 -> InitInstance()
********************************************************/
BOOL Clesson05App::InitInstance()
{
	Clesson05Dlg dlg;
	LoginDlg login;
	INT_PTR nResponse = login.DoModal();
	if (IDCANCEL == nResponse)
		return FALSE;
	nResponse = dlg.DoModal();
	return FALSE;

}


