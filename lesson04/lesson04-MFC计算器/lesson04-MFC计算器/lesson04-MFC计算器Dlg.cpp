
// lesson04-MFC计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lesson04-MFC计算器.h"
#include "lesson04-MFC计算器Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson04MFC计算器Dlg 对话框



Clesson04MFC计算器Dlg::Clesson04MFC计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LESSON04MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clesson04MFC计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clesson04MFC计算器Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDRESULT1, &Clesson04MFC计算器Dlg::OnBnClickedResult1)
	ON_BN_CLICKED(IDRESULT2, &Clesson04MFC计算器Dlg::OnBnClickedResult2)
	ON_BN_CLICKED(IDRESULT3, &Clesson04MFC计算器Dlg::OnBnClickedResult3)
	ON_BN_CLICKED(IDRESULT4, &Clesson04MFC计算器Dlg::OnBnClickedResult4)
END_MESSAGE_MAP()


// Clesson04MFC计算器Dlg 消息处理程序

BOOL Clesson04MFC计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Clesson04MFC计算器Dlg::OnPaint()
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Clesson04MFC计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clesson04MFC计算器Dlg::OnBnClickedResult1()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM1, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM1, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft + fright);
	SetDlgItemText(IDC_RESULT1, tmp);
}


void Clesson04MFC计算器Dlg::OnBnClickedResult2()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM2, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM2, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft - fright);
	SetDlgItemText(IDC_RESULT2, tmp);

}


void Clesson04MFC计算器Dlg::OnBnClickedResult3()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM3, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM3, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft * fright);
	SetDlgItemText(IDC_RESULT3, tmp);
}


void Clesson04MFC计算器Dlg::OnBnClickedResult4()
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
