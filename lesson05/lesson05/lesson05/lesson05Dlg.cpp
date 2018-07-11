
// lesson05Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lesson05.h"
#include "lesson05Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson05Dlg 对话框



Clesson05Dlg::Clesson05Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LESSON05_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clesson05Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clesson05Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &Clesson05Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &Clesson05Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &Clesson05Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIVI, &Clesson05Dlg::OnBnClickedDivi)
	ON_COMMAND(ID_MENU_CANCEL, &Clesson05Dlg::OnMenuCancel)
END_MESSAGE_MAP()


/*****************************************************
	part 3 系统自动接管这些消息
	1)	WM_INITDIALG
	2)	WM_COMMAND
	3)	IDOK
	4)	IDCANCEL
*****************************************************/
void Clesson05Dlg::OnOK()
{
}
void Clesson05Dlg::OnCancel()
{
	CDialog::OnCancel();
}
BOOL Clesson05Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Clesson05Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR Clesson05Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Clesson05Dlg::OnBnClickedAdd()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM1, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM1, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft + fright);
	SetDlgItemText(IDC_RESULT1, tmp);
}


void Clesson05Dlg::OnBnClickedSub()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM2, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM2, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft - fright);
	SetDlgItemText(IDC_RESULT2, tmp);
}


void Clesson05Dlg::OnBnClickedMul()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM3, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM3, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft * fright);
	SetDlgItemText(IDC_RESULT3, tmp);
}


void Clesson05Dlg::OnBnClickedDivi()
{
	CString tmp;//, tmp_right, tmp_result;
	GetDlgItemText(IDC_LPARAM4, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM4, tmp);
	double fright = _tstof(tmp);
	if (0 == fright)
	{
		SetDlgItemText(IDC_RESULT4, _T("被除数不能为0或为空"));
		return;
	}
	tmp.Format(_T("%lf"), fleft / fright);
	SetDlgItemText(IDC_RESULT4, tmp);
}


void Clesson05Dlg::OnMenuCancel()
{
	CDialog::OnCancel();
}
