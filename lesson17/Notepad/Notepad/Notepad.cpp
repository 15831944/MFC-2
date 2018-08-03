#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CNotepadApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


CNotepadApp::CNotepadApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}

CNotepadApp theApp;

/********************************************
part 2 ���¶���ϵͳ����.INI�ļ�����·��
	1) �Զ������ϵͳ·����C��.WIN10ϵͳ��дC��ҪȨ��
	2) 	free((LPTSTR)m_pszProfileName);
		m_pszProfileName = (LPCTSTR)malloc(256);
		_tcscpy((LPTSTR)m_pszProfileName, _T("./notepad.ini"));
********************************************/
/********************************************
part 3 (LPCTSTR)���͵ı���,��const���޸�
	1) ǿ��ת������(LPTSTR)m_pszProfileName
********************************************/

/********************************************
part 5 ����ע�����
	1) SetRegistryKey(_T("NotePad"));
********************************************/
BOOL CNotepadApp::InitInstance()
{
	SetRegistryKey(_T("NotePad_TEst"));


	//free((LPTSTR)m_pszProfileName);
	//m_pszProfileName = (LPCTSTR)malloc(256);
	//_tcscpy_s((LPTSTR)m_pszProfileName, 128, _T("./notepad.ini"));


	CNotepadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}

