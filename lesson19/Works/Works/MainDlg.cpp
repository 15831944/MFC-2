// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Works.h"
#include "MainDlg.h"
#include "afxdialogex.h"


// CMainDlg �Ի���

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


// CMainDlg ��Ϣ�������


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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
