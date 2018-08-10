// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Works.h"
#include "MainDlg.h"
#include "afxdialogex.h"


// CMainDlg 对话框

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


// CMainDlg 消息处理程序


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
	// TODO: 在此添加控件通知处理程序代码
}
