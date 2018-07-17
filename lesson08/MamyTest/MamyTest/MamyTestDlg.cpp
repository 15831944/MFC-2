#include "stdafx.h"
#include "MamyTest.h"
#include "MamyTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMamyTestDlg::CMamyTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAMYTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMamyTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMamyTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMamyTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMamyTestDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL CMamyTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMamyTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMamyTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMamyTestDlg::OnBnClickedButton1()
{
	CString str1 = _T("aaaa");
	CString str2 = _T("123");
	CString str3;

	str3 = str1 + str2;

	str3 = _T('!') + str1;

	str3 = str2 + _T('!');

	str3 = str1 + L'A';

	str3 = L'A' + str2;

	MessageBox(str3);
}


void CMamyTestDlg::OnBnClickedButton2()
{
	CString str(_T("Soccer is best, but hockey is quicker!"));

	int n = str.Delete(6, 3);

	MessageBox(str);

}
