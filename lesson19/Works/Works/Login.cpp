#include "stdafx.h"
#include "Works.h"
#include "Login.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DLG, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLogin::OnBnClickedCancel)
	ON_WM_TIMER()
END_MESSAGE_MAP()


BOOL CLogin::CreateAdmin()
{
	CFile file;
	if (!file.Open(_T("Admin.dat"), CFile::modeCreate | CFile::modeWrite))
		return FALSE;
	SAdmin admin = { _T("admin"),_T("admin"),1 };
	file.Write(&admin, sizeof(admin));
	file.Close();
	return TRUE;
}

BOOL CLogin::CheckPass(const CString& szPass, const CString& szName)
{
	CFile file;
	if (!file.Open(_T("Admin.dat"), CFile::modeRead))
	{
		CreateAdmin();
	}
	SAdmin admin;
	while (file.Read(&admin, sizeof(admin)) == sizeof(admin))
	{
		if (!szName.CompareNoCase(admin.sName))
		{
			if (szPass == admin.sPass)
			{
				theApp.m_Admin = admin;
				return TRUE;
			}
		}
	}
	return FALSE;
}

void CLogin::OnBnClickedOk()
{
	CString szName, szPass;
	GetDlgItemText(IDC_ACCOUNT, szName);
	GetDlgItemText(IDC_PASSWORK, szPass);

	if (!CheckPass(szPass, szName))
	{
		AfxMessageBox(_T("账户错误!"));
		return;
	}
	

	CDialogEx::OnOK();
}


void CLogin::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


BOOL CLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 1000, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CLogin::OnTimer(UINT_PTR nIDEvent)
{
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%d年%02d月%02d日 %d:%d:%d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	GetDlgItem(IDC_TIME)->SetWindowText(str);

	CDialogEx::OnTimer(nIDEvent);
}





