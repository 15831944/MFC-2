// LoginDlg.cpp : ʵ���ļ�
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
	1)	�Լ���LoginDlg���OnInitDialog()ʵ��,���û����
	2)	��ȡ��ǰʱ��:	CTime time = CTime::GetCurrentTime();
	3)	�޸�Static Text��ť������:	GetDlgItem(IDC_TIME)->SetWindowText(str); 
	4)	ֻ��һ���Գ�ʼ��,ʱ�䶨����,��ȥ��ʱ��OnTimer()
********************************************************/
BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//���ö�ʱ��
	SetTimer(1, 1000, NULL);

	//ֻ��һ���Գ�ʼ��,ʱ�䶨����,��ȥ��ʱ��OnTimer()
	//CTime time = CTime::GetCurrentTime();
	//CString str;
	//str.Format(_T("%d��%02d��%02d�� %d:%d:%d"),
	//	time.GetYear(), time.GetMonth(), time.GetDay(),
	//	time.GetHour(), time.GetMinute(), time.GetSecond());
	//GetDlgItem(IDC_TIME)->SetWindowText(str);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
	part 8	��ʱ��
	1)	���ö�ʱ��: ��OnInitDialog()���� SetTimer(1, 1000, NULL);
	2)	��ʱ�����:	(UINT_PTR nIDEvent)
********************************************************/
void LoginDlg::OnTimer(UINT_PTR nIDEvent)
{
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%d��%02d��%02d�� %d:%d:%d"),
		time.GetYear(), time.GetMonth(), time.GetDay(),
		time.GetHour(), time.GetMinute(), time.GetSecond());
	GetDlgItem(IDC_TIME)->SetWindowText(str);
	CDialogEx::OnTimer(nIDEvent);
}
