
// lesson05.cpp : ����Ӧ�ó��������Ϊ��
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
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
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
	part 2	MFC�Ի���������Ϣ����
	1)	Ϊһ���Ի���ģ�彨��һ����֮������CDialog��CDialogEx������
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

