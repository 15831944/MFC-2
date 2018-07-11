
// lesson03-TestMegDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lesson03-TestMeg.h"
#include "lesson03-TestMegDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson03TestMegDlg 对话框



Clesson03TestMegDlg::Clesson03TestMegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LESSON03TESTMEG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clesson03TestMegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clesson03TestMegDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &Clesson03TestMegDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &Clesson03TestMegDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &Clesson03TestMegDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIVI, &Clesson03TestMegDlg::OnBnClickedDivi)
END_MESSAGE_MAP()


// Clesson03TestMegDlg 消息处理程序

BOOL Clesson03TestMegDlg::OnInitDialog()
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

void Clesson03TestMegDlg::OnPaint()
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
HCURSOR Clesson03TestMegDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clesson03TestMegDlg::OnBnClickedAdd()
{
	int nLeft = GetDlgItemInt(IDC_LPARAM1, NULL, TRUE);
	int nRight = GetDlgItemInt(IDC_RPARAM1);
	SetDlgItemInt(IDC_RESULT1, nLeft + nRight);
}


void Clesson03TestMegDlg::OnBnClickedSub()
{
	int nLeft = GetDlgItemInt(IDC_LPARAM2, NULL, TRUE);
	int nRight = GetDlgItemInt(IDC_RPARAM2);
	SetDlgItemInt(IDC_RESULT2, nLeft - nRight);
}


void Clesson03TestMegDlg::OnBnClickedMul()
{
	int nLeft = GetDlgItemInt(IDC_LPARAM3, NULL, TRUE);
	int nRight = GetDlgItemInt(IDC_RPARAM3);
	SetDlgItemInt(IDC_RESULT3, nLeft * nRight);
}


void Clesson03TestMegDlg::OnBnClickedDivi()
{
	int nRight = GetDlgItemInt(IDC_RPARAM4);
	if (0 == nRight)
	{
		SetDlgItemText(IDC_RESULT4, _T("被除数不能为0或空"));
		return;
	}
	int nLeft = GetDlgItemInt(IDC_LPARAM4, NULL, TRUE);

	SetDlgItemInt(IDC_RESULT4, nLeft / nRight);
}
