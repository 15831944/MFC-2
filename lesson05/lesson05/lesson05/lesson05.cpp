
// lesson05.cpp : ����Ӧ�ó��������Ϊ��
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
	part 5	MFC	������֮�� -> ��Ϣ�������
********************************************************/
BEGIN_MESSAGE_MAP(Clesson05App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

Clesson05App::Clesson05App()
{
	// ֧����������������
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
	part 2	MFC�Ի���������Ϣ����
	1)	Ϊһ���Ի���ģ�彨��һ����֮������CDialog��CDialogEx������
	2)	����Ҫ�����Ի����������ඨ��һ������, ���ö������DoModal��Ա����
	3)	MFC���Ҫ����һ����Ϣ, ֻҪ������, ѡ��������������Ի�����
	4)	����Ϣ�б��оͿ���ѡ������Ҫ����Ϣ, ˫�����ɽ�����Ϣӳ�亯��
	5)	��Ϣӳ�亯������: һ����Ϣ(��һ������) ��Ӧһ�������ĵ�ַ

********************************************************/

/********************************************************
	part 4	MFC	������֮һ -> InitInstance()
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


