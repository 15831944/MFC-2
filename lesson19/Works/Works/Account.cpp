// Account.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Works.h"
#include "Account.h"
#include "afxdialogex.h"


// CAccount �Ի���

IMPLEMENT_DYNAMIC(CAccount, CDialogEx)

CAccount::CAccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ACCOUNT, pParent)
{

}

CAccount::~CAccount()
{
}

void CAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAccount, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAccount::OnBnClickedOk)
END_MESSAGE_MAP()


// CAccount ��Ϣ�������


void CAccount::OnBnClickedOk()
{
	
	CDialogEx::OnOK();
}
