// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lesson05.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN, pParent)
{
}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(ID_LOGIN, &LoginDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDCANCEL, &LoginDlg::OnBnClickedCancel)
	ON_WM_TIMER()
END_MESSAGE_MAP()

/********************************************************
	part 7	
	1)	自己做LoginDlg类的OnInitDialog()实现,不用基类的
	2)	获取当前时间:	CTime time = CTime::GetCurrentTime();
	3)	修改Static Text按钮的内容:	GetDlgItem(IDC_TIME)->SetWindowText(str); 
	4)	只能一次性初始化,时间定格了,我去定时器OnTimer()
********************************************************/
BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//设置定时器
	SetTimer(1, 1000, NULL);

	//只能一次性初始化,时间定格了,我去定时器OnTimer()
	//CTime time = CTime::GetCurrentTime();
	//CString str;
	//str.Format(_T("%d年%02d月%02d日 %d:%d:%d"),
	//	time.GetYear(), time.GetMonth(), time.GetDay(),
	//	time.GetHour(), time.GetMinute(), time.GetSecond());
	//GetDlgItem(IDC_TIME)->SetWindowText(str);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void LoginDlg::OnBnClickedLogin()
{
	TCHAR tmp_name[32] = { 0 };
	TCHAR tmp_key[32] = { 0 };
	GetDlgItemText(IDC_ACCOUNT, tmp_name, sizeof(tmp_name));
	GetDlgItemText(IDC_KEY, tmp_key, sizeof(tmp_key));
	if (0 != _tcscmp(tmp_key, _T("admin")) || 0 != _tcscmp(tmp_name, _T("admin")))
	{
		MessageBox(_T(" Accounts errors!"), _T("Error"), NULL);
		return;
	}
	EndDialog(IDOK);
	//EndDialog(IDCANCEL);
}

void LoginDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}





/********************************************************
	part 8	定时器
	1)	设置定时器: 到OnInitDialog()设置 SetTimer(1, 1000, NULL);
	2)	定时器编号:	(UINT_PTR nIDEvent)
********************************************************/
void LoginDlg::OnTimer(UINT_PTR nIDEvent)
{
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%d年%02d月%02d日 %d:%d:%d"),
		time.GetYear(), time.GetMonth(), time.GetDay(),
		time.GetHour(), time.GetMinute(), time.GetSecond());
	GetDlgItem(IDC_TIME)->SetWindowText(str);
	CDialogEx::OnTimer(nIDEvent);
}
