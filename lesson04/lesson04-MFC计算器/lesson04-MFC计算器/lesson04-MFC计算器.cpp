
// lesson04-MFC计算器.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "lesson04-MFC计算器.h"
#include "lesson04-MFC计算器Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson04MFC计算器App

BEGIN_MESSAGE_MAP(Clesson04MFC计算器App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Clesson04MFC计算器App 构造

Clesson04MFC计算器App::Clesson04MFC计算器App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Clesson04MFC计算器App 对象

Clesson04MFC计算器App theApp;


// Clesson04MFC计算器App 初始化

BOOL Clesson04MFC计算器App::InitInstance()
{

	Clesson04MFC计算器Dlg dlg;

	INT_PTR nResponse = dlg.DoModal();

	//返回错误值	
	DWORD dwError = GetLastError();

	return FALSE;
}

