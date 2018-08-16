#include "stdafx.h"
#include "Works.h"
#include "MainDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAD_DIALOG, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_INFO, &CMainDlg::OnBnClickedInfo)
	ON_BN_CLICKED(IDC_ADMIN, &CMainDlg::OnBnClickedAdmin)
	ON_BN_CLICKED(IDC_LOGIN, &CMainDlg::OnBnClickedLogin)
END_MESSAGE_MAP()

void CMainDlg::OnBnClickedInfo()
{
	EndDialog(IDC_INFO);
}


void CMainDlg::OnBnClickedAdmin()
{
	EndDialog(IDC_ADMIN);
}


void CMainDlg::OnBnClickedLogin()
{
	EndDialog(IDC_LOGIN);
}

/*******************************************
part 1 窗口摧毁/隐藏和禁用
	1)	摧毁窗口,窗口不可复原
		GetDlgItem(IDC_ADMIN)->DestroyWindow();
	2)	隐藏窗口,随时可调出
		GetDlgItem(IDC_ADMIN)->ShowWindow(SW_HIDE);
	3)	窗口禁用,成灰色
		GetDlgItem(IDC_ADMIN)->EnableWindow(FALSE);
*******************************************/
BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str = _T("控制面板 - ");
	str += theApp.m_Admin.sName;
	str += _T("(");
	str += theApp.m_Admin.nPrior ? _T("普通") : _T("高级");
	str += _T(")");
	SetWindowText(str);

	if (theApp.m_Admin.nPrior)
	{
		//GetDlgItem(IDC_ADMIN)->DestroyWindow();
		//GetDlgItem(IDC_ADMIN)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ADMIN)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
