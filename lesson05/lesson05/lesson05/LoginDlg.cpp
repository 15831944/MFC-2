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
END_MESSAGE_MAP()

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
